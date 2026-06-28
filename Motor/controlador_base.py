#!/usr/bin/env python3
"""
ControladorBase — Nó ROS 2
Subscriber : /cmd_vel  (geometry_msgs/Twist)
Publisher  : /wheel_states (sensor_msgs/JointState)
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import JointState

import lgpio
import time
import threading
import math

# ── Geometria do robô ──────────────────────────────────────────────────────────
WHEEL_RADIUS = 0.034
WHEEL_BASE   = 0.218

# ── Pinos dos encoders ─────────────────────────────────────────────────────────
ENC_L_A = 26
ENC_R_A = 5

# ── Pinos dos motores ──────────────────────────────────────────────────────────
ENBA = 12   # PWM Motor Direito
IN1  = 23
IN2  = 24
ENBB = 13   # PWM Motor Esquerdo
IN3  = 27
IN4  = 22
FREQ = 1000

PPR_MAP = {'left': 618, 'right': 616}
OMEGA_WINDOW = 0.3

PWM_MIN = 20
PWM_MAX = 100

# ── PID ────────────────────────────────────────────────────────────────────────
class PID:
    def __init__(self, kp, ki, kd, out_min, out_max):
        self.kp, self.ki, self.kd = kp, ki, kd
        self.out_min, self.out_max = out_min, out_max
        self.integral   = 0.0
        self.prev_error = 0.0

    def reset(self):
        self.integral   = 0.0
        self.prev_error = 0.0

    def update(self, error, dt):
        if dt <= 0:
            return 0.0
        self.integral += error * dt
        self.integral  = max(-50.0, min(50.0, self.integral))
        deriv          = (error - self.prev_error) / dt
        self.prev_error = error
        out = self.kp * error + self.ki * self.integral + self.kd * deriv
        return max(self.out_min, min(self.out_max, out))

# ── Nó principal ───────────────────────────────────────────────────────────────
class ControladorBase(Node):

    KP, KI, KD = 3.0, 1.5, 0.05
    CONTROL_HZ  = 20

    def __init__(self):
        super().__init__('controlador_base')

        # Parâmetros ROS (sobrescrevíveis via launch / CLI)
        self.declare_parameter('kp', self.KP)
        self.declare_parameter('ki', self.KI)
        self.declare_parameter('kd', self.KD)
        self.declare_parameter('wheel_radius', WHEEL_RADIUS)
        self.declare_parameter('wheel_base',   WHEEL_BASE)

        kp = self.get_parameter('kp').value
        ki = self.get_parameter('ki').value
        kd = self.get_parameter('kd').value
        self.wheel_radius = self.get_parameter('wheel_radius').value
        self.wheel_base   = self.get_parameter('wheel_base').value

        # PID independente por roda
        self.pid_l = PID(kp, ki, kd, -30, 30)
        self.pid_r = PID(kp, ki, kd, -30, 30)

        # Setpoints (rad/s por roda) — atualizados pelo subscriber
        self.omega_ref_l = 0.0
        self.omega_ref_r = 0.0
        self.cmd_lock    = threading.Lock()

        # Estado dos encoders
        self.pulse_times = {'left': [], 'right': []}
        self.enc_lock    = threading.Lock()

        # GPIO
        self._gpio_setup()

        # Subscriber /cmd_vel
        self.sub_cmd = self.create_subscription(
            Twist, '/cmd_vel', self._cmd_vel_cb, 10)

        # Publisher /wheel_states
        self.pub_js = self.create_publisher(JointState, '/wheel_states', 10)

        # Timer de controle
        self._t_prev    = time.monotonic()
        self._pwm_l     = PWM_MIN
        self._pwm_r     = PWM_MIN
        self.ctrl_timer = self.create_timer(
            1.0 / self.CONTROL_HZ, self._control_cb)

        self.get_logger().info('ControladorBase iniciado.')

    # ── GPIO ───────────────────────────────────────────────────────────────────
    def _gpio_setup(self):
        self.h = lgpio.gpiochip_open(0)

        for pin in [ENC_L_A, ENC_R_A]:
            lgpio.gpio_claim_input(self.h, pin)
            lgpio.gpio_claim_alert(self.h, pin, lgpio.RISING_EDGE)

        self.cb_l = lgpio.callback(
            self.h, ENC_L_A, lgpio.RISING_EDGE, self._make_enc_cb('left'))
        self.cb_r = lgpio.callback(
            self.h, ENC_R_A, lgpio.RISING_EDGE, self._make_enc_cb('right'))

        for pin in [ENBA, IN1, IN2, ENBB, IN3, IN4]:
            lgpio.gpio_claim_output(self.h, pin)

        self._motors_stop()

    def _make_enc_cb(self, side):
        def cbf(chip, gpio, level, timestamp):
            now = time.monotonic()
            with self.enc_lock:
                self.pulse_times[side].append(now)
                cutoff = now - 2.0
                self.pulse_times[side] = [
                    t for t in self.pulse_times[side] if t >= cutoff]
        return cbf

    # ── Odometria ──────────────────────────────────────────────────────────────
    def _calc_omega(self, side):
        with self.enc_lock:
            times = list(self.pulse_times[side])
        if len(times) < 2:
            return 0.0
        now    = time.monotonic()
        recent = [t for t in times if t >= now - OMEGA_WINDOW]
        if len(recent) < 2:
            return 0.0
        dt = recent[-1] - recent[0]
        if dt <= 0:
            return 0.0
        return ((len(recent) - 1) / PPR_MAP[side] / dt) * 2 * math.pi

    # ── Subscriber callback ────────────────────────────────────────────────────
    def _cmd_vel_cb(self, msg: Twist):
        """
        Converte Twist → ω de cada roda.

        Cinemática do robô diferencial:
            v  = msg.linear.x        (m/s)
            wz = msg.angular.z       (rad/s — positivo = anti-horário)

            ωL = (v - wz * d) / r
            ωR = (v + wz * d) / r
            onde d = WHEEL_BASE / 2
        """
        v  = msg.linear.x
        wz = msg.angular.z
        d  = self.wheel_base / 2.0
        r  = self.wheel_radius

        ref_l = (v - wz * d) / r
        ref_r = (v + wz * d) / r

        with self.cmd_lock:
            self.omega_ref_l = ref_l
            self.omega_ref_r = ref_r

        # Reseta integradores ao mudar de comando (evita windup acumulado)
        self.pid_l.reset()
        self.pid_r.reset()

    # ── Loop de controle ───────────────────────────────────────────────────────
    def _control_cb(self):
        now = time.monotonic()
        dt  = now - self._t_prev
        self._t_prev = now

        with self.cmd_lock:
            ref_l = self.omega_ref_l
            ref_r = self.omega_ref_r

        ol = self._calc_omega('left')
        or_ = self._calc_omega('right')

        # ── feedforward + PID ──────────────────────────────────────────────────
        ff_l = self._feedforward(ref_l)
        ff_r = self._feedforward(ref_r)

        # O erro usa o módulo da referência; o sinal é tratado na direção
        err_l = abs(ref_l) - ol
        err_r = abs(ref_r) - or_

        correction_l = self.pid_l.update(err_l, dt)
        correction_r = self.pid_r.update(err_r, dt)

        self._pwm_l = ff_l + correction_l
        self._pwm_r = ff_r + correction_r

        # Aplica sentido e PWM
        self._motors_apply(ref_l, ref_r, self._pwm_l, self._pwm_r)

        # Publica estado das rodas
        self._publish_joint_state(ol, or_)

    def _feedforward(self, omega_ref):
        """Interpola linearmente entre os pontos calibrados."""
        if abs(omega_ref) < 0.1:
            return 0.0
        pwm = 30 + (abs(omega_ref) - 5.0) * (10.0 / 2.6)
        return max(float(PWM_MIN), min(float(PWM_MAX), pwm))

    # ── Controle de direção ────────────────────────────────────────────────────
    def _motors_apply(self, ref_l, ref_r, pwm_l, pwm_r):
        """
        Aplica PWM e direção independentemente para cada roda.
        ref > 0 → frente / ref < 0 → ré / ref ≈ 0 → parado
        """
        DEADBAND = 0.1   # rad/s — abaixo disso, para a roda

        # ── Roda esquerda (ENBB / IN3 / IN4) ──────────────────────────────────
        if abs(ref_l) < DEADBAND:
            lgpio.tx_pwm(self.h, ENBB, FREQ, 0)
            lgpio.gpio_write(self.h, IN3, 0)
            lgpio.gpio_write(self.h, IN4, 0)
        elif ref_l > 0:   # frente
            lgpio.tx_pwm(self.h, ENBB, FREQ, self._clamp(pwm_l))
            lgpio.gpio_write(self.h, IN3, 1)
            lgpio.gpio_write(self.h, IN4, 0)
        else:             # ré
            lgpio.tx_pwm(self.h, ENBB, FREQ, self._clamp(pwm_l))
            lgpio.gpio_write(self.h, IN3, 0)
            lgpio.gpio_write(self.h, IN4, 1)

        # ── Roda direita (ENBA / IN1 / IN2) ───────────────────────────────────
        if abs(ref_r) < DEADBAND:
            lgpio.tx_pwm(self.h, ENBA, FREQ, 0)
            lgpio.gpio_write(self.h, IN1, 0)
            lgpio.gpio_write(self.h, IN2, 0)
        elif ref_r > 0:   # frente
            lgpio.tx_pwm(self.h, ENBA, FREQ, self._clamp(pwm_r))
            lgpio.gpio_write(self.h, IN1, 1)
            lgpio.gpio_write(self.h, IN2, 0)
        else:             # ré
            lgpio.tx_pwm(self.h, ENBA, FREQ, self._clamp(pwm_r))
            lgpio.gpio_write(self.h, IN1, 0)
            lgpio.gpio_write(self.h, IN2, 1)

    def _clamp(self, v):
        return max(PWM_MIN, min(PWM_MAX, int(abs(v))))

    def _motors_stop(self):
        for pin in [IN1, IN2, IN3, IN4]:
            lgpio.gpio_write(self.h, pin, 0)
        lgpio.tx_pwm(self.h, ENBA, FREQ, 0)
        lgpio.tx_pwm(self.h, ENBB, FREQ, 0)

    # ── Publisher ──────────────────────────────────────────────────────────────
    def _publish_joint_state(self, ol, or_):
        msg = JointState()
        msg.header.stamp    = self.get_clock().now().to_msg()
        msg.name            = ['left_wheel', 'right_wheel']
        msg.velocity        = [ol, or_]   # rad/s medidos
        msg.position        = []
        msg.effort          = [float(self._pwm_l), float(self._pwm_r)]
        self.pub_js.publish(msg)

    # ── Destrutor ──────────────────────────────────────────────────────────────
    def destroy_node(self):
        self._motors_stop()
        self.cb_l.cancel()
        self.cb_r.cancel()
        lgpio.gpiochip_close(self.h)
        super().destroy_node()


# ── Entrypoint ─────────────────────────────────────────────────────────────────
def main(args=None):
    rclpy.init(args=args)
    node = ControladorBase()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()