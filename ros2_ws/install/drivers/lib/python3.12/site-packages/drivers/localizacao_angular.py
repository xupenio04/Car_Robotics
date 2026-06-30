import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import LaserScan
import math

OFFSET_CALIBRACAO = -65.0  # graus, resultado do desafio 3

class LocalizacaoAngular(Node):
    def __init__(self):
        super().__init__('localizacao_angular')
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.subscription = self.create_subscription(
            LaserScan, '/scan', self.scan_callback, qos)
        self.get_logger().info('Localização angular iniciada - posicione um objeto isolado à frente do robô')

    def scan_callback(self, msg):
        angle_min = msg.angle_min
        angle_increment = msg.angle_increment

        valid = [
            (r, angle_min + i * angle_increment)
            for i, r in enumerate(msg.ranges)
            if r > msg.range_min and r < msg.range_max and not math.isinf(r)
        ]

        if not valid:
            return

        min_range, min_angle = min(valid, key=lambda x: x[0])
        min_angle_deg = math.degrees(min_angle)
        angulo_robo = min_angle_deg - OFFSET_CALIBRACAO

        self.get_logger().info(
            f'Distância: {min_range:.3f} m | '
            f'Ângulo lidar: {min_angle_deg:.2f}° | '
            f'Ângulo robô: {angulo_robo:.2f}°'
        )

def main(args=None):
    rclpy.init(args=args)
    node = LocalizacaoAngular()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
