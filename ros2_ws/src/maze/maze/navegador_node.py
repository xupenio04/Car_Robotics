#!/usr/bin/env python3
"""
Navegador autônomo — VFH no corredor + decisão na bifurcação (servo + câmera).

Subscriber : /scan, /wheel_states
Publisher  : /cmd_vel
Clients    : /mover_servo, /detecta_objeto
"""

import math
from enum import Enum, auto

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import JointState, LaserScan
from servo_interfaces.srv import MoverServo
from camera_interfaces.srv import DetectaObjeto

from maze.vfh import VFHNavigator, media_distancia_graus

WHEEL_RADIUS = 0.034
WHEEL_BASE = 0.218


class Estado(Enum):
    NAVEGAR_CORREDOR = auto()
    ESCANEAR_RAMOS = auto()
    GIRAR_RAMO = auto()
    SEGUIR_ALVO = auto()
    CONCLUIDO = auto()


class FaseEscaneamento(Enum):
    MOVER_ESQUERDA = auto()
    DETECTAR_ESQUERDA = auto()
    MOVER_DIREITA = auto()
    DETECTAR_DIREITA = auto()
    CENTRALIZAR = auto()


class NavegadorNode(Node):

    def __init__(self):
        super().__init__('navegador')

        self.declare_parameter('v_max', 0.15)
        self.declare_parameter('safety_dist', 0.35)
        self.declare_parameter('robot_radius', 0.20)
        self.declare_parameter('vfh_threshold', 0.5)
        self.declare_parameter('bifurcacao_frente_min', 1.0)
        self.declare_parameter('bifurcacao_lateral_min', 0.6)
        self.declare_parameter('angulo_servo_esquerda', -45.0)
        self.declare_parameter('angulo_servo_direita', 45.0)
        self.declare_parameter('angulo_giro', 1.57)
        self.declare_parameter('velocidade_giro', 0.35)
        self.declare_parameter('cor_alvo', 'verde')
        self.declare_parameter('self_reflection_angles', [-150.0, -120.0, 120.0, 150.0])

        refl = self.get_parameter('self_reflection_angles').value
        refl_pairs = []
        for i in range(0, len(refl) - 1, 2):
            refl_pairs.append((float(refl[i]), float(refl[i + 1])))

        self.vfh = VFHNavigator(
            v_max=self.get_parameter('v_max').value,
            safety_dist=self.get_parameter('safety_dist').value,
            robot_radius=self.get_parameter('robot_radius').value,
            wheel_base=WHEEL_BASE,
            threshold=self.get_parameter('vfh_threshold').value,
            self_reflection_angles=refl_pairs,
        )

        self.cor_alvo = self.get_parameter('cor_alvo').value
        self.bifurcacao_frente_min = self.get_parameter('bifurcacao_frente_min').value
        self.bifurcacao_lateral_min = self.get_parameter('bifurcacao_lateral_min').value
        self.angulo_servo_esq = self.get_parameter('angulo_servo_esquerda').value
        self.angulo_servo_dir = self.get_parameter('angulo_servo_direita').value
        self.angulo_giro = self.get_parameter('angulo_giro').value
        self.velocidade_giro = self.get_parameter('velocidade_giro').value

        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)

        self.scan: LaserScan | None = None
        self.wz_atual = 0.0

        self.estado = Estado.NAVEGAR_CORREDOR
        self.fase_escaneamento: FaseEscaneamento | None = None
        self.ramo_escolhido: str | None = None
        self.resultado_esquerda = None
        self.resultado_direita = None
        self.giro_acumulado = 0.0
        self._ultimo_tick = self.get_clock().now()

        self.create_subscription(LaserScan, '/scan', self._scan_cb, qos)
        self.create_subscription(JointState, '/wheel_states', self._wheel_cb, 10)
        self.pub_cmd = self.create_publisher(Twist, '/cmd_vel', 10)

        self.cli_servo = self.create_client(MoverServo, '/mover_servo')
        self.cli_cam = self.create_client(DetectaObjeto, '/detecta_objeto')

        self.create_timer(0.1, self._loop)

        self.get_logger().info('Navegador iniciado — estado: NAVEGAR_CORREDOR')

    def _scan_cb(self, msg: LaserScan):
        self.scan = msg

    def _wheel_cb(self, msg: JointState):
        if len(msg.velocity) < 2:
            return
        ol, or_ = msg.velocity[0], msg.velocity[1]
        self.wz_atual = WHEEL_RADIUS / WHEEL_BASE * (or_ - ol)

    def _parar(self):
        self.pub_cmd.publish(Twist())

    def _publicar_vel(self, v: float, w: float):
        msg = Twist()
        msg.linear.x = float(v)
        msg.angular.z = float(w)
        self.pub_cmd.publish(msg)

    def _bifurcacao_detectada(self, scan: LaserScan) -> bool:
        frente = media_distancia_graus(
            scan.ranges, scan.angle_min, scan.angle_increment,
            scan.range_min, scan.range_max, -15.0, 15.0,
        )
        esquerda = media_distancia_graus(
            scan.ranges, scan.angle_min, scan.angle_increment,
            scan.range_min, scan.range_max, 45.0, 90.0,
        )
        direita = media_distancia_graus(
            scan.ranges, scan.angle_min, scan.angle_increment,
            scan.range_min, scan.range_max, -90.0, -45.0,
        )

        detectada = (
            frente > self.bifurcacao_frente_min
            and esquerda > self.bifurcacao_lateral_min
            and direita > self.bifurcacao_lateral_min
        )

        if detectada:
            self.get_logger().info(
                f'Bifurcação detectada — frente={frente:.2f}m '
                f'esq={esquerda:.2f}m dir={direita:.2f}m'
            )
        return detectada

    def _aguardar_servicos(self) -> bool:
        if not self.cli_servo.wait_for_service(timeout_sec=0.0):
            self.get_logger().warn('Aguardando /mover_servo...', throttle_duration_sec=5.0)
            return False
        if not self.cli_cam.wait_for_service(timeout_sec=0.0):
            self.get_logger().warn('Aguardando /detecta_objeto...', throttle_duration_sec=5.0)
            return False
        return True

    def _iniciar_escaneamento(self):
        if not self._aguardar_servicos():
            self.get_logger().error('Serviços indisponíveis — retomando corredor')
            self.estado = Estado.NAVEGAR_CORREDOR
            return

        self.fase_escaneamento = FaseEscaneamento.MOVER_ESQUERDA
        self.resultado_esquerda = None
        self.resultado_direita = None
        self._chamar_servo(self.angulo_servo_esq, self._apos_mover_esquerda)

    def _chamar_servo(self, angulo: float, done_cb):
        req = MoverServo.Request()
        req.angulo = float(angulo)
        future = self.cli_servo.call_async(req)
        future.add_done_callback(done_cb)

    def _chamar_camera(self, done_cb):
        req = DetectaObjeto.Request()
        future = self.cli_cam.call_async(req)
        future.add_done_callback(done_cb)

    def _apos_mover_esquerda(self, future):
        try:
            resp = future.result()
            if not resp.sucesso:
                self.get_logger().warn(f'Servo esquerda: {resp.mensagem}')
        except Exception as exc:
            self.get_logger().error(f'Erro ao mover servo esquerda: {exc}')

        self.fase_escaneamento = FaseEscaneamento.DETECTAR_ESQUERDA
        self._chamar_camera(self._apos_detectar_esquerda)

    def _apos_detectar_esquerda(self, future):
        try:
            self.resultado_esquerda = future.result()
            self.get_logger().info(
                f'Escaneamento esquerda: detectado={self.resultado_esquerda.detectado} '
                f'cor={self.resultado_esquerda.cor}'
            )
        except Exception as exc:
            self.get_logger().error(f'Erro na câmera (esquerda): {exc}')
            self.resultado_esquerda = None

        self.fase_escaneamento = FaseEscaneamento.MOVER_DIREITA
        self._chamar_servo(self.angulo_servo_dir, self._apos_mover_direita)

    def _apos_mover_direita(self, future):
        try:
            resp = future.result()
            if not resp.sucesso:
                self.get_logger().warn(f'Servo direita: {resp.mensagem}')
        except Exception as exc:
            self.get_logger().error(f'Erro ao mover servo direita: {exc}')

        self.fase_escaneamento = FaseEscaneamento.DETECTAR_DIREITA
        self._chamar_camera(self._apos_detectar_direita)

    def _apos_detectar_direita(self, future):
        try:
            self.resultado_direita = future.result()
            self.get_logger().info(
                f'Escaneamento direita: detectado={self.resultado_direita.detectado} '
                f'cor={self.resultado_direita.cor}'
            )
        except Exception as exc:
            self.get_logger().error(f'Erro na câmera (direita): {exc}')
            self.resultado_direita = None

        self.fase_escaneamento = FaseEscaneamento.CENTRALIZAR
        self._chamar_servo(0.0, self._apos_centralizar)

    def _tem_cor_alvo(self, resp) -> bool:
        if resp is None:
            return False
        return resp.detectado and resp.cor == self.cor_alvo

    def _apos_centralizar(self, future):
        try:
            future.result()
        except Exception as exc:
            self.get_logger().warn(f'Erro ao centralizar servo: {exc}')

        esq = self._tem_cor_alvo(self.resultado_esquerda)
        dir_ = self._tem_cor_alvo(self.resultado_direita)

        if esq and not dir_:
            self.ramo_escolhido = 'esquerda'
        elif dir_ and not esq:
            self.ramo_escolhido = 'direita'
        elif esq and dir_:
            area_esq = 0
            area_dir = 0
            if self.resultado_esquerda.centro_x >= 0:
                area_esq = 1
            if self.resultado_direita.centro_x >= 0:
                area_dir = 1
            self.ramo_escolhido = 'esquerda' if area_esq >= area_dir else 'direita'
        else:
            self.get_logger().warn(
                f'Objeto {self.cor_alvo} não encontrado — girando à esquerda por padrão'
            )
            self.ramo_escolhido = 'esquerda'

        self.get_logger().info(f'Ramo escolhido: {self.ramo_escolhido}')
        self.fase_escaneamento = None
        self.giro_acumulado = 0.0
        self.estado = Estado.GIRAR_RAMO

    def _loop(self):
        if self.scan is None:
            return

        agora = self.get_clock().now()
        dt = (agora - self._ultimo_tick).nanoseconds * 1e-9
        self._ultimo_tick = agora

        if self.estado == Estado.NAVEGAR_CORREDOR:
            if self._bifurcacao_detectada(self.scan):
                self._parar()
                self.estado = Estado.ESCANEAR_RAMOS
                self._iniciar_escaneamento()
                return

            v, w = self.vfh.compute(self.scan, target_angle=0.0)
            self._publicar_vel(v, w)

        elif self.estado == Estado.ESCANEAR_RAMOS:
            self._parar()

        elif self.estado == Estado.GIRAR_RAMO:
            sinal = 1.0 if self.ramo_escolhido == 'esquerda' else -1.0
            alvo = sinal * self.angulo_giro

            twist = Twist()
            twist.angular.z = sinal * self.velocidade_giro
            self.pub_cmd.publish(twist)

            if abs(self.wz_atual) > 0.05:
                self.giro_acumulado += self.wz_atual * dt
            else:
                self.giro_acumulado += sinal * self.velocidade_giro * dt

            if abs(self.giro_acumulado) >= abs(alvo):
                self._parar()
                self.get_logger().info(
                    f'Giro concluído ({math.degrees(self.giro_acumulado):.1f}°) '
                    f'— seguindo ramo {self.ramo_escolhido}'
                )
                self.estado = Estado.SEGUIR_ALVO

        elif self.estado == Estado.SEGUIR_ALVO:
            alvo = math.pi / 2 if self.ramo_escolhido == 'esquerda' else -math.pi / 2
            v, w = self.vfh.compute(self.scan, target_angle=alvo)
            self._publicar_vel(v, w)

        elif self.estado == Estado.CONCLUIDO:
            self._parar()


def main(args=None):
    rclpy.init(args=args)
    node = NavegadorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node._parar()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
