import cv2
import numpy as np
import mediapipe as mp
from mediapipe.tasks import python
from mediapipe.tasks.python import vision

# Load model tay
base_options = python.BaseOptions(
    model_asset_path="E:\DUT\CODE\Fundamental courses of the major\Xu ly anh\hand_landmarker.task"
)

options = vision.HandLandmarkerOptions(
    base_options=base_options,
    num_hands=1
)

detector = vision.HandLandmarker.create_from_options(options)

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    mp_image = mp.Image(
        image_format=mp.ImageFormat.SRGB,
        data=rgb
    )

    result = detector.detect(mp_image)

    if result.hand_landmarks:
        hand = result.hand_landmarks[0]

        # Ngón cái (4) & ngón trỏ (8)
        h, w, _ = frame.shape
        x1 = int(hand[4].x * w)
        y1 = int(hand[4].y * h)
        x2 = int(hand[8].x * w)
        y2 = int(hand[8].y * h)

        # Vẽ điểm
        cv2.circle(frame, (x1, y1), 8, (0, 0, 255), -1)
        cv2.circle(frame, (x2, y2), 8, (0, 0, 255), -1)
        cv2.line(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)

        # Khoảng cách
        distance = np.hypot(x2 - x1, y2 - y1)

        # Map sang mức âm lượng giả lập
        volume = np.interp(distance, [30, 200], [0, 100])
        volume = int(volume)

        cv2.putText(frame, f"Volume: {volume}%",
                    (30, 60),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    1.2, (255, 0, 0), 3)

    cv2.imshow("Hand Gesture Control", frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
