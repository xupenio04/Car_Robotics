import lgpio
import time
import threading

# Pinos dos encoders (canais A e B de cada encoder)
ENC_L_A = 26   # Encoder esquerdo - Canal A
ENC_L_B = 16  # Encoder esquerdo - Canal B
ENC_R_A = 5  # Encoder direito  - Canal A
ENC_R_B = 6  # Encoder direito  - Canal B

# Contadores e estado de direção
counters = {'left': 0, 'right': 0}
directions = {'left': '?', 'right': '?'}
last_a = {'left': 0, 'right': 0}

# Lock para acesso thread-safe aos contadores
lock = threading.Lock()

def make_callback(side, channel):
    """Fábrica de callbacks: retorna uma função específica para cada canal."""
    def cbf(chip, gpio, level, timestamp):
        with lock:
            if channel == 'A':
                # No flanco de subida do canal A, lemos B para determinar direção
                b_pin = ENC_L_B if side == 'left' else ENC_R_B
                b_level = lgpio.gpio_read(h, b_pin)
                if level == 1:  # RISING
                    if b_level == 0:
                        directions[side] = 'Frente →'
                        counters[side] += 1
                    else:
                        directions[side] = '← Trás'
                        counters[side] -= 1
                else:           # FALLING
                    if b_level == 1:
                        directions[side] = 'Frente →'
                        counters[side] += 1
                    else:
                        directions[side] = '← Trás'
                        counters[side] -= 1
    return cbf

def display_loop():
    """Exibe os contadores em tempo real no terminal."""
    try:
        while running:
            with lock:
                cl = counters['left']
                cr = counters['right']
                dl = directions['left']
                dr = directions['right']
            print(
                f"\r  Esq: {cl:+6d} pulsos [{dl}]   |   Dir: {cr:+6d} pulsos [{dr}]   ",
                end='', flush=True
            )
            time.sleep(0.1)
    except Exception:
        pass

# Abre o chip GPIO
h = lgpio.gpiochip_open(0)

# Configura todos os pinos como entrada e alerta
for pin in [ENC_L_A, ENC_L_B, ENC_R_A, ENC_R_B]:
    lgpio.gpio_claim_input(h, pin)
    lgpio.gpio_claim_alert(h, pin, lgpio.RISING_EDGE)

# Registra callbacks apenas nos canais A (para contagem + direção)
cb_left  = lgpio.callback(h, ENC_L_A, lgpio.RISING_EDGE, make_callback('left',  'A'))
cb_right = lgpio.callback(h, ENC_R_A, lgpio.RISING_EDGE, make_callback('right', 'A'))

print("=== Desafio 1 - Leitura dos Codificadores ===")
print("Gire as rodas manualmente. Pressione Ctrl+C para sair.\n")

running = True
display_thread = threading.Thread(target=display_loop, daemon=True)
display_thread.start()

try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    running = False
    cb_left.cancel()
    cb_right.cancel()
    lgpio.gpiochip_close(h)
    print(f"\n\nContagem final → Esquerda: {counters['left']}  |  Direita: {counters['right']}")
    print("Encerrando.")