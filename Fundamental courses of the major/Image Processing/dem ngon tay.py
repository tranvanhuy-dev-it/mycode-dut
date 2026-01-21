import cv2
import mediapipe as mp

mp_hands = mp.solutions.hands
hands = mp_hands.Hands(
    min_detection_confidence=0.7,
    min_tracking_confidence=0.7
)
mp_draw = mp.solutions.drawing_utils

cap = cv2.VideoCapture(0)

tips = [4, 8, 12, 16, 20]

while True:
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    result = hands.process(rgb)

    finger_count = 0

    if result.multi_hand_landmarks:
        for idx, hand in enumerate(result.multi_hand_landmarks):
            lm = hand.landmark

            hand_label = result.multi_handedness[idx].classification[0].label

            if hand_label == "Right":
                if lm[4].x < lm[3].x:
                    finger_count += 1
            else: 
                if lm[4].x > lm[3].x:
                    finger_count += 1

            for i in range(1, 5):
                if lm[tips[i]].y < lm[tips[i] - 2].y:
                    finger_count += 1

            mp_draw.draw_landmarks(frame, hand, mp_hands.HAND_CONNECTIONS)

            cv2.putText(frame, hand_label,
                        (int(lm[0].x * frame.shape[1]), 
                         int(lm[0].y * frame.shape[0]) - 10),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        1, (255, 255, 0), 2)

    cv2.putText(frame, f"Fingers: {finger_count}",
                (30, 60),
                cv2.FONT_HERSHEY_SIMPLEX,
                1.5, (0, 0, 255), 3)

    cv2.imshow("Finger Counter", frame)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
