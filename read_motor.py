# Import the lgpio module
import lgpio

ENC_1 =5

# Definition of the callback function for event detection
def cbf(chip, gpio, level, timestamp):
    print(chip, gpio, level, timestamp)

# Open the gpio chip
h = lgpio.gpiochip_open(0)

# Set the pin 23 as input
lgpio.gpio_claim_input(h, ENC_1)

# Set the pin 23 as alert
# BOTH_EDGES, RISING_EDGE (default), or FALLING_EDGE.
lgpio.gpio_claim_alert(h, ENC_1, lgpio.BOTH_EDGES)
# Add event detection for pin 23
# BOTH_EDGES, RISING_EDGE (default), or FALLING_EDGE.
cb1 = lgpio.callback(h, ENC_1, lgpio.BOTH_EDGES, cbf)

# To cancel callback cb1.
try: 
    while True:
        pass
except KeyboardInterrupt:
    cb1.cancel()