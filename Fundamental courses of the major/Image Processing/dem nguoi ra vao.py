from ultralytics import YOLO
import cv2

model = YOLO("yolov8n.pt")
cap = cv2.VideoCapture(0)

# Vị trí line (ngang)
line_y = 300

# Lưu vị trí cũ của mỗi ID
track_history = {}

in_count = 0
out_count = 0

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Detect + Track
    results = model.track(
        frame,
        persist=True,
        conf=0.5,
        classes=[0]  # chỉ nhận diện person
    )

    # Vẽ line
    cv2.line(frame, (0, line_y), (frame.shape[1], line_y), (0, 0, 255), 2)

    if results[0].boxes.id is not None:
        boxes = results[0].boxes.xyxy.cpu().numpy()
        ids = results[0].boxes.id.cpu().numpy()

        for box, track_id in zip(boxes, ids):
            x1, y1, x2, y2 = map(int, box)
            cx = (x1 + x2) // 2
            cy = (y1 + y2) // 2

            # Lưu vị trí cũ
            if track_id not in track_history:
                track_history[track_id] = cy
            else:
                prev_y = track_history[track_id]

                # Đi xuống → IN
                if prev_y < line_y and cy >= line_y:
                    in_count += 1

                # Đi lên → OUT
                elif prev_y > line_y and cy <= line_y:
                    out_count += 1

                track_history[track_id] = cy

            # Vẽ box + ID
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0,255,0), 2)
            cv2.putText(frame, f"ID {int(track_id)}",
                        (x1, y1 - 10),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.6, (0,255,0), 2)

            cv2.circle(frame, (cx, cy), 5, (255,0,0), -1)

    # Hiển thị số lượng
    cv2.putText(frame, f"IN: {in_count}", (20, 40),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0), 2)
    cv2.putText(frame, f"OUT: {out_count}", (20, 80),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2)

    cv2.imshow("People Counter", frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
