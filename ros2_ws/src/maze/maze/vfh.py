"""Vector Field Histogram (VFH) — implementação pura, sem dependência ROS."""

import math
from typing import List, Optional, Sequence, Tuple


def _sector_index(angle: float, n_sectors: int) -> int:
    """Mapeia ângulo do lidar (rad) para índice do histograma [0, n_sectors)."""
    sector_angle = 2.0 * math.pi / n_sectors
    return int((angle + math.pi) / sector_angle) % n_sectors


def _angular_distance_sectors(a: int, b: int, n_sectors: int) -> int:
    return min(abs(a - b), n_sectors - abs(a - b))


class VFHNavigator:
    """Calcula (v, w) a partir de um LaserScan e direção alvo."""

    def __init__(
        self,
        n_sectors: int = 72,
        robot_radius: float = 0.20,
        safety_dist: float = 0.35,
        wheel_base: float = 0.218,
        v_max: float = 0.15,
        threshold: float = 0.5,
        self_reflection_angles: Optional[Sequence[Tuple[float, float]]] = None,
    ):
        self.n_sectors = n_sectors
        self.sector_angle = 2.0 * math.pi / n_sectors
        self.robot_radius = robot_radius
        self.safety_dist = safety_dist
        self.wheel_base = wheel_base
        self.v_max = v_max
        self.threshold = threshold
        self.self_reflection_angles = list(self_reflection_angles or [])

    def is_self_reflection(self, angle: float, distance: float) -> bool:
        """Filtra leituras do próprio chassi (ajustar na calibração)."""
        angle_deg = math.degrees(angle)
        for lo, hi in self.self_reflection_angles:
            if lo <= angle_deg <= hi and distance < 0.25:
                return True
        return False

    def build_histogram(self, ranges: Sequence[float], angle_min: float,
                        angle_increment: float, range_min: float,
                        range_max: float) -> List[float]:
        hist = [0.0] * self.n_sectors

        for i, r in enumerate(ranges):
            if not (range_min < r < range_max) or math.isinf(r) or math.isnan(r):
                continue

            angle = angle_min + i * angle_increment
            if self.is_self_reflection(angle, r):
                continue

            sector = _sector_index(angle, self.n_sectors)
            weight = max(0.0, self.safety_dist - r) / self.safety_dist

            half_arc = math.atan2(self.robot_radius, max(r, 0.01))
            span = int(math.ceil(half_arc / self.sector_angle)) + 1

            for offset in range(-span, span + 1):
                hist[(sector + offset) % self.n_sectors] += weight

        return self._smooth(hist)

    def _smooth(self, hist: List[float]) -> List[float]:
        kernel = [0.1, 0.2, 0.4, 0.2, 0.1]
        pad = len(kernel) // 2
        extended = hist[-pad:] + hist + hist[:pad]
        return [
            sum(extended[i + j] * kernel[j] for j in range(len(kernel)))
            for i in range(self.n_sectors)
        ]

    def compute_from_histogram(self, hist: List[float],
                               target_angle: float = 0.0) -> Tuple[float, float]:
        """Retorna velocidade linear e angular (m/s, rad/s)."""
        free = [i for i, h in enumerate(hist) if h < self.threshold]
        if not free:
            return 0.0, 0.0

        target_sector = _sector_index(target_angle, self.n_sectors)
        best = min(
            free,
            key=lambda s: _angular_distance_sectors(s, target_sector, self.n_sectors),
        )

        steering = (best * self.sector_angle) - math.pi
        v = self.v_max * (1.0 - abs(steering) / math.pi)
        v = max(0.05, v)
        w = 2.0 * v * math.sin(steering) / self.wheel_base
        return v, w

    def compute(self, scan, target_angle: float = 0.0) -> Tuple[float, float]:
        hist = self.build_histogram(
            scan.ranges,
            scan.angle_min,
            scan.angle_increment,
            scan.range_min,
            scan.range_max,
        )
        return self.compute_from_histogram(hist, target_angle)


def media_distancia_graus(
    ranges: Sequence[float],
    angle_min: float,
    angle_increment: float,
    range_min: float,
    range_max: float,
    min_deg: float,
    max_deg: float,
) -> float:
    """Média das distâncias em um setor angular (graus, 0 = frente)."""
    valores = []
    for i, r in enumerate(ranges):
        if not (range_min < r < range_max) or math.isinf(r) or math.isnan(r):
            continue
        ang_deg = math.degrees(angle_min + i * angle_increment)
        if min_deg <= ang_deg <= max_deg:
            valores.append(r)

    if not valores:
        return 0.0
    return sum(valores) / len(valores)
