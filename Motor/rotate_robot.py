import lgpio
import time
import threading
import math

# ── Geometria do robô ──────────────────────────────────────────────────────────
WHEEL_RADIUS = 0.034   # r  (metros)
WHEEL_BASE   = 0.218   # 2d (metros)

# ── Pinos dos encoders ─────────────────────────────────────────────────────────
ENC_L_A = 26
ENC_L_B = 16
ENC_R_A = 5
ENC_R_B = 6

# ── Pinos dos motores ──────────────────────────────────────────────────────────
ENBA = 12
IN1  = 23
IN2  = 24
ENBB = 13
IN3  = 27
IN4  = 22
FREQ = 1000

# ── Encoder ───────────────────────────────────────────────────────────────────
PPR_MAP = {'left': 618, 'right': 616}

# ── Estado compartilhado ───────────────────────────────────────────────────────
counters    = {'left': 0, 'right': 0}
pulse_times = {'left': [], 'right': []}
lock    = threading.Lock()
running = True

# ── Callbacks ─────────────────────────────────────────────────────────────────
def make_callback(side):
    def cbf(chip, gpio, level, timestamp):
        now = time.monotonic()
        with lock:
            counters[side] += 1
            pulse_times[side].append(now)
            cutoff = now - 2.0
            pulse_times[side] = [t for t in pulse_times[side] if t >= cutoff]
    return cbf

# ── Velocidade angular medida ──────────────────────────────────────────────────
OMEGA_WINDOW = 0.3

def calc_omega(side):
    with lock:
        times = list(pulse_times[side])
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

# ── Controle dos motores ───────────────────────────────────────────────────────
PWM_MIN = 20
PWM_MAX = 100

def pwm_clamp(v):
    return max(PWM_MIN, min(PWM_MAX, abs(v)))

def motors_set_spin(pwm_left, pwm_right, clockwise=True):
    """
    Para girar no próprio eixo, as rodas giram em sentidos opostos.
    clockwise=True  → roda direita para trás, esquerda para frente
    clockwise=False → roda esquerda para trás, direita para frente
    """
    lgpio.tx_pwm(h, ENBB, FREQ, pwm_clamp(pwm_left))
    lgpio.tx_pwm(h, ENBA, FREQ, pwm_clamp(pwm_right))
    if clockwise:
        # Esquerda: frente
        lgpio.gpio_write(h, IN3, 1); lgpio.gpio_write(h, IN4, 0)
        # Direita: trás
        lgpio.gpio_write(h, IN1, 0); lgpio.gpio_write(h, IN2, 1)
    else:
        # Esquerda: trás
        lgpio.gpio_write(h, IN3, 0); lgpio.gpio_write(h, IN4, 1)
        # Direita: frente
        lgpio.gpio_write(h, IN1, 1); lgpio.gpio_write(h, IN2, 0)

def motors_stop():
    for pin in [IN1, IN2, IN3, IN4]:
        lgpio.gpio_write(h, pin, 0)
    lgpio.tx_pwm(h, ENBA, FREQ, 0)
    lgpio.tx_pwm(h, ENBB, FREQ, 0)

# ── PID por roda ───────────────────────────────────────────────────────────────
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
        self.integral  += error * dt
        self.integral   = max(-50, min(50, self.integral))
        derivative      = (error - self.prev_error) / dt
        self.prev_error = error
        output = self.kp * error + self.ki * self.integral + self.kd * derivative
        return max(self.out_min, min(self.out_max, output))

# ── Parâmetros de rotação ──────────────────────────────────────────────────────
KP, KI, KD = 3.0, 1.5, 0.05

pid_l = PID(KP, KI, KD, -30, 30)
pid_r = PID(KP, KI, KD, -30, 30)

# Velocidade angular desejada para cada roda durante o spin
# Reutiliza feedforward do desafio 3 (mesmo PWM ~33%)
OMEGA_REF_SPIN = 5.882   # rad/s (mesmo setpoint, rodas opostas)

def feedforward(omega_ref):
    pwm = 30 + (omega_ref - 5.0) * (10.0 / 2.6)
    return max(PWM_MIN, min(PWM_MAX, pwm))

FF = feedforward(OMEGA_REF_SPIN)

# ── Quantos radianos o robô precisa girar ─────────────────────────────────────
TARGET_ANGLE   = 2 * math.pi          # 360°
CLOCKWISE      = True                  # sentido de rotação
CONTROL_HZ     = 20
CONTROL_DT     = 1.0 / CONTROL_HZ

control_log = []

# substitui a integração de ângulo no control_loop

# ── Parâmetros de rotação ──────────────────────────────────────────────────────
TARGET_ANGLE = 2 * math.pi          # 360°

# Pulsos necessários para 360° — cada roda percorre π*2d de arco
# arco_roda = π * WHEEL_BASE  →  pulsos = arco / (2π*r) * PPR
PULSOS_360_L = int(math.pi * WHEEL_BASE / (2 * math.pi * WHEEL_RADIUS) * PPR_MAP['left'])
PULSOS_360_R = int(math.pi * WHEEL_BASE / (2 * math.pi * WHEEL_RADIUS) * PPR_MAP['right'])

def control_loop():
    pid_l.reset(); pid_r.reset()
    pwm_l = FF
    pwm_r = FF

    t_start = time.monotonic()
    t_prev  = t_start

    # Snapshot dos contadores no início — mede só os pulsos desta manobra
    with lock:
        start_l = counters['left']
        start_r = counters['right']

    motors_set_spin(pwm_l, pwm_r, CLOCKWISE)

    while running:
        time.sleep(CONTROL_DT)
        now = time.monotonic()
        dt  = now - t_prev
        t_prev = now

        ol  = calc_omega('left')
        or_ = calc_omega('right')

        with lock:
            delta_l = counters['left']  - start_l
            delta_r = counters['right'] - start_r

        # Ângulo estimado pela média dos pulsos das duas rodas
        angle_l = (delta_l / PPR_MAP['left'])  * (2 * math.pi * WHEEL_RADIUS / WHEEL_BASE) * 2
        angle_r = (delta_r / PPR_MAP['right']) * (2 * math.pi * WHEEL_RADIUS / WHEEL_BASE) * 2
        angle_traveled = (angle_l + angle_r) / 2.0

        err_l = OMEGA_REF_SPIN - ol
        err_r = OMEGA_REF_SPIN - or_

        pwm_l = FF + pid_l.update(err_l, dt)
        pwm_r = FF + pid_r.update(err_r, dt)

        motors_set_spin(pwm_l, pwm_r, CLOCKWISE)
        control_log.append((now - t_start, ol, or_, pwm_l, pwm_r,
                             math.degrees(angle_traveled), delta_l, delta_r))

        if angle_traveled >= TARGET_ANGLE:
            break

    motors_stop()

# ── Display (adiciona colunas de pulsos) ───────────────────────────────────────
def display_loop():
    print(f"\n{'t(s)':>6} | {'ωL':>7} | {'ωR':>7} | "
          f"{'PWM_L':>6} | {'PWM_R':>6} | {'°':>8} | {'ΔpulL':>6} | {'ΔpulR':>6}")
    print("-" * 70)
    try:
        while running:
            if control_log:
                t, ol, or_, pl, pr, ang, dl, dr = control_log[-1]
                print(f"{t:>6.2f} | {ol:>7.3f} | {or_:>7.3f} | "
                      f"{pl:>6.1f} | {pr:>6.1f} | {ang:>8.1f} | {dl:>6} | {dr:>6}")
            time.sleep(0.25)
    except Exception:
        pass

# ── Setup GPIO ─────────────────────────────────────────────────────────────────
h = lgpio.gpiochip_open(0)

for pin in [ENC_L_A, ENC_L_B, ENC_R_A, ENC_R_B]:
    lgpio.gpio_claim_input(h, pin)
    lgpio.gpio_claim_alert(h, pin, lgpio.RISING_EDGE)

cb_left  = lgpio.callback(h, ENC_L_A, lgpio.RISING_EDGE, make_callback('left'))
cb_right = lgpio.callback(h, ENC_R_A, lgpio.RISING_EDGE, make_callback('right'))

for pin in [ENBA, IN1, IN2, ENBB, IN3, IN4]:
    lgpio.gpio_claim_output(h, pin)

# ── Main ───────────────────────────────────────────────────────────────────────
print("=== Desafio 5 - Rotação no Próprio Eixo ===")
print(f"Alvo: 360°  |  ω_roda = {OMEGA_REF_SPIN:.3f} rad/s  |  FF = {FF:.1f}%")
print(f"Sentido: {'horário' if CLOCKWISE else 'anti-horário'}\n")

display_thread = threading.Thread(target=display_loop, daemon=True)
control_thread = threading.Thread(target=control_loop, daemon=False)

display_thread.start()
time.sleep(0.1)
control_thread.start()

try:
    control_thread.join()
except KeyboardInterrupt:
    pass
finally:
    running = False
    motors_stop()
    cb_left.cancel()
    cb_right.cancel()
    lgpio.gpiochip_close(h)
    with lock:
        print(f"\nPulsos finais → Esq: {counters['left']}  |  Dir: {counters['right']}")
    ang_final = control_log[-1][5] if control_log else 0
    dl_final  = control_log[-1][6] if control_log else 0
    dr_final  = control_log[-1][7] if control_log else 0
    print(f"Ângulo estimado: {ang_final:.1f}°  |  "
          f"Pulsos usados → Esq: {dl_final}  Dir: {dr_final}")
    print(f"Pulsos esperados → Esq: {PULSOS_360_L}  Dir: {PULSOS_360_R}")