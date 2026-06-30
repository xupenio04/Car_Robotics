import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import LaserScan
import math

class LidarCalibracao(Node):
    def __init__(self):
        super().__init__('lidar_calibracao')
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.subscription = self.create_subscription(
            LaserScan, '/scan', self.scan_callback, qos)
        self.get_logger().info('Calibração iniciada - posicione o robô de frente para a parede')

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

        self.get_logger().info(
            f'Menor distância: {min_range:.3f} m | Ângulo exato: {min_angle_deg:.2f}°'
        )

def main(args=None):
    rclpy.init(args=args)
    node = LidarCalibracao()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
