import lgpio
import time
import threading
import math

WHEEL_RADIUS = 0.034  # metros (3 cm)
# ── Pinos dos encoders ─────────────────────────────────────────────────────────
ENC_L_A = 26
ENC_L_B = 16
ENC_R_A = 5
ENC_R_B = 6

# ── Pinos dos motores ──────────────────────────────────────────────────────────
ENBA = 12   # PWM Motor Direito
IN1  = 23
IN2  = 24
ENBB = 13   # PWM Motor Esquerdo
IN3  = 27
IN4  = 22
FREQ = 1000

# ── Constante do encoder ───────────────────────────────────────────────────────
PPR_E = 618
PPR_D = 616

# ── Estado compartilhado ───────────────────────────────────────────────────────
counters    = {'left': 0, 'right': 0}
pulse_times = {'left': [], 'right': []}
lock    = threading.Lock()
running = True

# ── Callbacks dos encoders ─────────────────────────────────────────────────────
def make_callback(side):
    def cbf(chip, gpio, level, timestamp):
        now = time.monotonic()            # base de tempo confiável
        with lock:
            counters[side] += 1
            pulse_times[side].append(now)
            cutoff = now - 2.0
            pulse_times[side] = [t for t in pulse_times[side] if t >= cutoff]
    return cbf

# ── Cálculo de velocidade angular ──────────────────────────────────────────────
PPR_MAP = {'left': PPR_E, 'right': PPR_D}   # cada lado usa seu próprio PPR

def calc_omega(side):
    times = pulse_times[side]
    if len(times) < 2:
        return 0.0
    now    = time.monotonic()
    recent = [t for t in times if t >= now - 0.5]
    if len(recent) < 2:
        return 0.0
    dt = recent[-1] - recent[0]
    if dt <= 0:
        return 0.0
    return ((len(recent) - 1) / PPR_MAP[side] / dt) * 2 * math.pi

# ── Controle dos motores ───────────────────────────────────────────────────────
def motors_set(pwm_duty):
    """Liga ambos os motores para frente com o duty cycle informado (0-100)."""
    lgpio.tx_pwm(h, ENBA, FREQ, pwm_duty)
    lgpio.tx_pwm(h, ENBB, FREQ, pwm_duty)
    lgpio.gpio_write(h, IN1, 1)
    lgpio.gpio_write(h, IN2, 0)
    lgpio.gpio_write(h, IN3, 1)
    lgpio.gpio_write(h, IN4, 0)

def motors_stop():
    lgpio.gpio_write(h, IN1, 0); lgpio.gpio_write(h, IN2, 0)
    lgpio.gpio_write(h, IN3, 0); lgpio.gpio_write(h, IN4, 0)
    lgpio.tx_pwm(h, ENBA, FREQ, 0)
    lgpio.tx_pwm(h, ENBB, FREQ, 0)

# ── Display ────────────────────────────────────────────────────────────────────
current_pwm = 0

def display_loop():
    print(f"\n{'Tempo(s)':>10} | {'PWM(%)':>6} | {'Pulsos Esq':>10} | "
          f"{'ω Esq(rad/s)':>13} | {'Pulsos Dir':>10} | {'ω Dir(rad/s)':>13}")
    print("-" * 75)
    t0 = time.time()
    try:
        while running:
            with lock:
                cl = counters['left']
                cr = counters['right']
            ol  = calc_omega('left')
            or_ = calc_omega('right')
            print(f"{time.time()-t0:>10.1f} | {current_pwm:>6} | {cl:>10d} | "
                  f"{ol:>13.3f} | {cr:>10d} | {or_:>13.3f}")
            time.sleep(0.5)
    except Exception:
        pass

# ── Setup GPIO ─────────────────────────────────────────────────────────────────
h = lgpio.gpiochip_open(0)

# Encoders
for pin in [ENC_L_A, ENC_L_B, ENC_R_A, ENC_R_B]:
    lgpio.gpio_claim_input(h, pin)
    lgpio.gpio_claim_alert(h, pin, lgpio.RISING_EDGE)

cb_left  = lgpio.callback(h, ENC_L_A, lgpio.RISING_EDGE, make_callback('left'))
cb_right = lgpio.callback(h, ENC_R_A, lgpio.RISING_EDGE, make_callback('right'))

# Motores
for pin in [ENBA, IN1, IN2, ENBB, IN3, IN4]:
    lgpio.gpio_claim_output(h, pin)

# ── Sequência de teste por PWM ─────────────────────────────────────────────────
PWM_LEVELS = [25,30,40,50]
DURATION   = 5   # segundos por nível

print("=== Desafio 2 - Velocidade Angular com PWM ===")
display_thread = threading.Thread(target=display_loop, daemon=True)
display_thread.start()

try:
    for pwm in PWM_LEVELS:
        current_pwm = pwm
        print(f"\n>>> PWM = {pwm}%")
        motors_set(pwm)
        time.sleep(DURATION)

    motors_stop()
    running = False
    time.sleep(0.6)   # deixa o display imprimir a última linha

except KeyboardInterrupt:
    running = False
    motors_stop()

finally:
    cb_left.cancel()
    cb_right.cancel()
    lgpio.gpiochip_close(h)
    with lock:
        print(f"\nContagem final → Esq: {counters['left']}  |  Dir: {counters['right']}")
    print("Encerrando.")