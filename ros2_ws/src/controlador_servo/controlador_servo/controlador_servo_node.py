#!/usr/bin/env python3

import lgpio
import time
import rclpy
from rclpy.node import Node
from servo_interfaces.srv import MoverServo

PINO_SERVO  = 17
FREQ        = 50
OFFSET_US   = 1500
US_POR_GRAU = 10
ANGULO_MIN  = -90
ANGULO_MAX  =  90
PASSO       = 2
DELAY       = 0.03

def angulo_para_dutycycle(angulo: float) -> float:
    pulso_us = OFFSET_US + (angulo * US_POR_GRAU)
    return (pulso_us / 20000.0) * 100.0

class ControladorServo(Node):

    def __init__(self):
        super().__init__('controlador_servo')

        self._h = lgpio.gpiochip_open(0)
        lgpio.gpio_claim_output(self._h, PINO_SERVO)

        self._angulo_atual = 0.0
        lgpio.tx_pwm(self._h, PINO_SERVO, FREQ,
                     angulo_para_dutycycle(self._angulo_atual))
        time.sleep(0.5)

        self._srv = self.create_service(
            MoverServo,
            'mover_servo',
            self._callback_mover
        )

        self.get_logger().info('ControladorServo pronto. Service: /mover_servo')

    def _callback_mover(self, request, response):
        angulo_alvo = float(request.angulo)

        if not (ANGULO_MIN <= angulo_alvo <= ANGULO_MAX):
            response.sucesso  = False
            response.mensagem = (
                f'Ângulo {angulo_alvo}° fora da faixa '
                f'[{ANGULO_MIN}°, {ANGULO_MAX}°]'
            )
            self.get_logger().warn(response.mensagem)
            return response

        self.get_logger().info(
            f'Movendo servo: {self._angulo_atual:.1f}° → {angulo_alvo:.1f}°'
        )

        try:
            self._mover_suave(self._angulo_atual, angulo_alvo)
            self._angulo_atual = angulo_alvo
            response.sucesso  = True
            response.mensagem = f'Servo posicionado em {angulo_alvo:.1f}°'
        except Exception as e:
            response.sucesso  = False
            response.mensagem = f'Erro ao mover servo: {str(e)}'
            self.get_logger().error(response.mensagem)

        return response

    def _mover_suave(self, atual: float, alvo: float):
        passo = PASSO if alvo >= atual else -PASSO
        ang   = atual
        while (passo > 0 and ang < alvo) or (passo < 0 and ang > alvo):
            lgpio.tx_pwm(self._h, PINO_SERVO, FREQ,
                         angulo_para_dutycycle(ang))
            time.sleep(DELAY)
            ang += passo
        lgpio.tx_pwm(self._h, PINO_SERVO, FREQ,
                     angulo_para_dutycycle(alvo))
        time.sleep(0.2)

    def destroy_node(self):
        self.get_logger().info('Encerrando: centralizando servo...')
        self._mover_suave(self._angulo_atual, 0.0)
        lgpio.tx_pwm(self._h, PINO_SERVO, FREQ, 0)
        lgpio.gpiochip_close(self._h)
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = ControladorServo()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
