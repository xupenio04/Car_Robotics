# Import the lgpio module
import lgpio

IN_PWM = 17

# Definition of the callback function for event detection
def cbf(chip, gpio, level, timestamp):
    print(chip, gpio, level, timestamp)

# Open the gpio chip
h = lgpio.gpiochip_open(0)

# Set the pin 23 as input
lgpio.gpio_claim_input(h, IN_PWM)

# Set the pin 23 as alert
# BOTH_EDGES, RISING_EDGE (default), or FALLING_EDGE.
lgpio.gpio_claim_alert(h, IN_PWM, lgpio.BOTH_EDGES)

# Add event detection for pin 23
# BOTH_EDGES, RISING_EDGE (default), or FALLING_EDGE.
cb1 = lgpio.callback(h, IN_PWM, lgpio.BOTH_EDGES, cbf)

# To cancel callback