import rclpy
from rclpy.node import Node
import cv2
import numpy as np
from camera_interfaces.srv import DetectaObjeto


PIPELINE = (
    "libcamerasrc ! "
    "video/x-raw,width=640,height=480,framerate=30/1 ! "
    "videoconvert ! "
    "video/x-raw,format=BGR ! "
    "appsink drop=true max-buffers=1 sync=false"
)


def capturar_frame():
    cap = cv2.VideoCapture(PIPELINE, cv2.CAP_GSTREAMER)
    if not cap.isOpened():
        return None
    for _ in range(30):
        cap.read()
    ret, frame = cap.read()
    cap.release()
    return frame if ret else None


def detectar(frame):
    frame = cv2.resize(frame, (320, 240))
    hsv   = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    kernel = np.ones((5, 5), np.uint8)

    candidatos = []

    # Vermelho
    m1 = cv2.inRange(hsv, np.array([0,   120, 70]), np.array([10,  255, 255]))
    m2 = cv2.inRange(hsv, np.array([170, 120, 70]), np.array([180, 255, 255]))
    mask_v = cv2.morphologyEx(cv2.bitwise_or(m1, m2), cv2.MORPH_OPEN,  kernel)
    mask_v = cv2.morphologyEx(mask_v,                  cv2.MORPH_CLOSE, kernel)
    contornos, _ = cv2.findContours(mask_v, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if contornos:
        maior = max(contornos, key=cv2.contourArea)
        if cv2.contourArea(maior) >= 500:
            candidatos.append(("vermelho", maior))

    # Verde
    mask_g = cv2.inRange(hsv, np.array([40, 70, 70]), np.array([80, 255, 255]))
    mask_g = cv2.morphologyEx(mask_g, cv2.MORPH_OPEN,  kernel)
    mask_g = cv2.morphologyEx(mask_g, cv2.MORPH_CLOSE, kernel)
    contornos, _ = cv2.findContours(mask_g, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if contornos:
        maior = max(contornos, key=cv2.contourArea)
        if cv2.contourArea(maior) >= 500:
            candidatos.append(("verde", maior))

    if not candidatos:
        return None

    cor, contorno = max(candidatos, key=lambda x: cv2.contourArea(x[1]))
    M  = cv2.moments(contorno)
    cx = int(M["m10"] / M["m00"])
    cy = int(M["m01"] / M["m00"])
    return cor, cx, cy


class CameraService(Node):
    def __init__(self):
        super().__init__("camera_service")
        self.srv = self.create_service(
            DetectaObjeto,
            "detecta_objeto",
            self.callback
        )
        self.get_logger().info("Serviço /detecta_objeto pronto.")

    def callback(self, request, response):
        self.get_logger().info("Requisição recebida — capturando imagem...")

        frame = capturar_frame()
        if frame is None:
            self.get_logger().error("Falha ao capturar imagem.")
            response.detectado = False
            response.cor       = ""
            response.centro_x  = -1
            response.centro_y  = -1
            return response

        resultado = detectar(frame)
        if resultado is None:
            self.get_logger().info("Nenhum objeto detectado.")
            response.detectado = False
            response.cor       = ""
            response.centro_x  = -1
            response.centro_y  = -1
        else:
            cor, cx, cy = resultado
            self.get_logger().info(f"Objeto {cor} em ({cx}, {cy})")
            response.detectado = True
            response.cor       = cor
            response.centro_x  = cx
            response.centro_y  = cy

        return response


def main(args=None):
    rclpy.init(args=args)
    node = CameraService()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
