import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import LaserScan
import math

class LidarNode(Node):
    def __init__(self):
        super().__init__('lidar_node')
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            qos)
        self.get_logger().info('Lidar node iniciado!')

    def scan_callback(self, msg):
        ranges = msg.ranges
        angle_min = msg.angle_min
        angle_increment = msg.angle_increment

        valid = [
            (r, angle_min + i * angle_increment)
            for i, r in enumerate(ranges)
            if r > msg.range_min and r < msg.range_max and not math.isinf(r)
        ]

        if not valid:
            self.get_logger().warn('Nenhuma leitura válida!')
            return

        min_range, min_angle = min(valid, key=lambda x: x[0])
        min_angle_deg = math.degrees(min_angle)

        self.get_logger().info(
            f'Menor distância: {min_range:.3f} m | Ângulo: {min_angle_deg:.1f} graus'
        )

def main(args=None):
    rclpy.init(args=args)
    node = LidarNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
