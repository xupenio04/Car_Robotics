import lgpio
import time

EN_SERVO =17 
FREQ = 1000

h = lgpio.gpiochip_open(0)

lgpio.gpio_claim_output(h, EN_SERVO)

# PWM 50%
lgpio.tx_pwm(h, EN_SERVO, FREQ, 50)


# Mantém ligado por 5 segundos
time.sleep(5)

lgpio.tx_pwm(h, EN_SERVO, FREQ, 0)

lgpio.gpiochip_close(h)