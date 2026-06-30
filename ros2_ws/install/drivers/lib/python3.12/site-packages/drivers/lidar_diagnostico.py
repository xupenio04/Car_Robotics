import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import LaserScan
import math

class LidarDiagnostico(Node):
    def __init__(self):
        super().__init__('lidar_diagnostico')
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        self.subscription = self.create_subscription(
            LaserScan, '/scan', self.scan_callback, qos)
        self.get_logger().info('Diagnóstico iniciado - mostrando distância mínima por setor de 10°')

    def scan_callback(self, msg):
        angle_min = msg.angle_min
        angle_increment = msg.angle_increment
        n = len(msg.ranges)

        # Agrupa em setores de 10 graus (-180 a 180)
        setores = {}
        for i, r in enumerate(msg.ranges):
            if r <= msg.range_min or r >= msg.range_max or math.isinf(r):
                continue
            angle_deg = math.degrees(angle_min + i * angle_increment)
            setor = int(angle_deg // 10) * 10
            if setor not in setores or r < setores[setor]:
                setores[setor] = r

        linha = ' | '.join(
            f'{s}°:{setores[s]:.2f}m' for s in sorted(setores.keys())
        )
        self.get_logger().info(linha)

def main(args=None):
    rclpy.init(args=args)
    node = LidarDiagnostico()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
