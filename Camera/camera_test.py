import cv2

# Pipeline GStreamer para captura via libcamera
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

ret, frame = cap.read()
cap.release()

if not ret:
    print("Erro: não foi possível capturar imagem.")
    exit(1)

print(f"Resolução original: {frame.shape[1]}x{frame.shape[0]}")

# Reduzir resolução para 320x240
frame_reduzido = cv2.resize(frame, (320, 240))
print(f"Resolução reduzida: {frame_reduzido.shape[1]}x{frame_reduzido.shape[0]}")

# Salvar imagem em disco
cv2.imwrite("imagem_capturada.jpg", frame_reduzido)
print("Imagem salva em: imagem_capturada.jpg")