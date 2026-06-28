import lgpio
import time
import threading
import math

# ── Geometria do robô ──────────────────────────────────────────────────────────
WHEEL_RADIUS = 0.034   # r  (metros)
WHEEL_BASE   = 0.143   # 2d (metros) — meça a distância entre os centros das rodas

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
OMEGA_WINDOW = 0.3   # janela menor = resposta mais rápida ao PID

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
PWM_MIN = 20   # abaixo disso o motor não gira
PWM_MAX = 100

def pwm_clamp(v):
    return max(PWM_MIN, min(PWM_MAX, v))

def motors_set(pwm_left, pwm_right):
    lgpio.tx_pwm(h, ENBB, FREQ, pwm_clamp(pwm_left))
    lgpio.tx_pwm(h, ENBA, FREQ, pwm_clamp(pwm_right))
    lgpio.gpio_write(h, IN1, 1); lgpio.gpio_write(h, IN2, 0)
    lgpio.gpio_write(h, IN3, 1); lgpio.gpio_write(h, IN4, 0)

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
        self.integral  = 0.0
        self.prev_error = 0.0

    def reset(self):
        self.integral   = 0.0
        self.prev_error = 0.0

    def update(self, error, dt):
        if dt <= 0:
            return 0.0
        self.integral  += error * dt
        # Anti-windup: clipa o integral
        self.integral   = max(-50, min(50, self.integral))
        derivative      = (error - self.prev_error) / dt
        self.prev_error = error
        output = self.kp * error + self.ki * self.integral + self.kd * derivative
        return max(self.out_min, min(self.out_max, output))

# ── Ganhos PID ─────────────────────────────────────────────────────────────────
# Ponto de partida conservador; ajuste Kp primeiro, depois Ki.
KP, KI, KD = 3.0, 1.5, 0.05

pid_l = PID(KP, KI, KD, -30, 30)
pid_r = PID(KP, KI, KD, -30, 30)

# ── Loop de controle ───────────────────────────────────────────────────────────
# Velocidade linear desejada → converte para ω_ref de cada roda
# υ = r/2 * (ωL + ωR)  →  para trajetória reta: ωL = ωR = υ / r

TARGET_LINEAR_SPEED = 0.20   # m/s  (≈ 20 cm/s, seguro para teste indoor)
OMEGA_REF = TARGET_LINEAR_SPEED / WHEEL_RADIUS   # rad/s alvo para cada roda

CONTROL_HZ  = 20             # frequências do loop de controle
CONTROL_DT  = 1.0 / CONTROL_HZ
DISTANCE    = 2.0            # metros a percorrer

# PWM base estimado para não começar do zero (feedforward)
# Em PWM=30% medimos ~5 rad/s; em PWM=40% ~7.6 rad/s. Interpola linearmente.
def feedforward(omega_ref):
    # rad/s → PWM%, baseado nas medições anteriores
    # ~5 rad/s @ 30%,  ~7.6 rad/s @ 40%
    pwm = 30 + (omega_ref - 5.0) * (10.0 / 2.6)
    return max(PWM_MIN, min(PWM_MAX, pwm))

FF = feedforward(OMEGA_REF)

# PWM iniciais (feedforward)
pwm_l = FF
pwm_r = FF

control_log = []   # (t, ωL, ωR, pwm_L, pwm_R)

def control_loop():
    global pwm_l, pwm_r
    pid_l.reset(); pid_r.reset()
    t_start = time.monotonic()
    t_prev  = t_start

    # Distância percorrida estimada por integração de υ
    distance_traveled = 0.0

    motors_set(pwm_l, pwm_r)

    while running:
        time.sleep(CONTROL_DT)
        now = time.monotonic()
        dt  = now - t_prev
        t_prev = now

        ol  = calc_omega('left')
        or_ = calc_omega('right')

        # υ = r/2 * (ωL + ωR)
        v_linear = WHEEL_RADIUS / 2.0 * (ol + or_)
        distance_traveled += v_linear * dt

        err_l = OMEGA_REF - ol
        err_r = OMEGA_REF - or_

        pwm_l = FF + pid_l.update(err_l, dt)
        pwm_r = FF + pid_r.update(err_r, dt)

        motors_set(pwm_l, pwm_r)
        control_log.append((now - t_start, ol, or_, pwm_l, pwm_r, distance_traveled))

        if distance_traveled >= DISTANCE:
            break

    motors_stop()

# ── Display ────────────────────────────────────────────────────────────────────
def display_loop():
    print(f"\n{'t(s)':>6} | {'ωL ref':>8} | {'ωL med':>8} | {'ωR ref':>8} | "
          f"{'ωR med':>8} | {'PWM_L':>6} | {'PWM_R':>6} | {'dist(m)':>8}")
    print("-" * 75)
    try:
        while running:
            if control_log:
                t, ol, or_, pl, pr, d = control_log[-1]
                print(f"{t:>6.2f} | {OMEGA_REF:>8.3f} | {ol:>8.3f} | "
                      f"{OMEGA_REF:>8.3f} | {or_:>8.3f} | "
                      f"{pl:>6.1f} | {pr:>6.1f} | {d:>8.3f}")
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
print("=== Desafio 3 - Controle PID de Velocidade ===")
print(f"Alvo: υ = {TARGET_LINEAR_SPEED} m/s  →  ω_ref = {OMEGA_REF:.3f} rad/s")
print(f"Feedforward inicial: PWM = {FF:.1f}%")
print(f"Percurso: {DISTANCE} m\n")

display_thread  = threading.Thread(target=display_loop,  daemon=True)
control_thread  = threading.Thread(target=control_loop,  daemon=False)

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
    dist_final = control_log[-1][5] if control_log else 0
    print(f"Distância estimada percorrida: {dist_final:.3f} m")
    print("Encerrando.")