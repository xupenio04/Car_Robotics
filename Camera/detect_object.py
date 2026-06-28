import cv2
import numpy as np

pipeline = (
    "libcamerasrc ! "
    "video/x-raw,width=640,height=480,framerate=30/1 ! "
    "videoconvert ! "
    "video/x-raw,format=BGR ! "
    "appsink drop=true max-buffers=1 sync=false"
)

cap = cv2.VideoCapture(pipeline, cv2.CAP_GSTREAMER)

if not cap.isOpened():
    print("Erro: não foi possível abrir a câmera.")
    exit(1)

# Aguardar AEC estabilizar
print("Aguardando estabilização da câmera...")
for _ in range(30):
    cap.read()

ret, frame = cap.read()
cap.release()

if not ret:
    print("Erro: não foi possível capturar imagem.")
    exit(1)

frame = cv2.resize(frame, (320, 240))
hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

mascara_vermelho1 = cv2.inRange(hsv, np.array([0,   120, 70]), np.array([10,  255, 255]))
mascara_vermelho2 = cv2.inRange(hsv, np.array([170, 120, 70]), np.array([180, 255, 255]))
mascara_vermelho  = cv2.bitwise_or(mascara_vermelho1, mascara_vermelho2)
mascara_verde     = cv2.inRange(hsv, np.array([40, 70, 70]),   np.array([80,  255, 255]))

def detectar_objeto(mascara, nome_cor, frame):
    kernel = np.ones((5, 5), np.uint8)
    mascara = cv2.morphologyEx(mascara, cv2.MORPH_OPEN,  kernel)
    mascara = cv2.morphologyEx(mascara, cv2.MORPH_CLOSE, kernel)

    contornos, _ = cv2.findContours(mascara, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if not contornos:
        print(f"[{nome_cor}] Nenhum objeto detectado.")
        return

    maior = max(contornos, key=cv2.contourArea)
    area  = cv2.contourArea(maior)

    if area < 500:
        print(f"[{nome_cor}] Região muito pequena (área={area:.0f}px²), ignorada.")
        return

    M  = cv2.moments(maior)
    cx = int(M["m10"] / M["m00"])
    cy = int(M["m01"] / M["m00"])
    x, y, w, h = cv2.boundingRect(maior)

    print(f"[{nome_cor}] Objeto detectado!")
    print(f"  Área         : {area:.0f} px²")
    print(f"  Centro       : ({cx}, {cy})")
    print(f"  Bounding box : x={x}, y={y}, w={w}, h={h}")

    cor_bgr = (0, 0, 255) if nome_cor == "Vermelho" else (0, 255, 0)
    cv2.rectangle(frame, (x, y), (x + w, y + h), cor_bgr, 2)
    cv2.circle(frame,   (cx, cy), 5, cor_bgr, -1)
    cv2.putText(frame, f"{nome_cor} ({cx},{cy})", (x, y - 8),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, cor_bgr, 1)

detectar_objeto(mascara_vermelho, "Vermelho", frame)
detectar_objeto(mascara_verde,    "Verde",    frame)

cv2.imwrite("deteccao_objeto.jpg", frame)
print("\nImagem anotada salva em: deteccao_objeto.jpg")