import sounddevice as sd
import numpy as np
import matplotlib.pyplot as plt

fs = [8000, 16000, 44100]
signals = {}

print("Hãy nói các câu giống nhau ở 3 lần ghi.")
print("Nhấn ENTER để lưu bản ghi và chuyển sang tần số tiếp theo.\n")
input("Nhấn ENTER để BẮT ĐẦU ghi...")

for f in fs:
    print(f"Đang ghi: {f} Hz")
    print("Nhấn ENTER để dừng ghi...")

    recorded = []
    def callback(indata, frames, time, status):
        recorded.append(indata.copy())

    with sd.InputStream(samplerate=f, channels=1, dtype='float32', callback=callback):
        input()

    signals[f] = np.concatenate(recorded, axis=0).flatten()
    
print("Phát tất cả các bản ghi:")
for f in fs:
    print(f"Đang phát {f} Hz...")
    sd.play(signals[f] * 3, f)
    sd.wait()
    print(f"Kích thước mẫu: {len(signals[f])}\n")

plt.figure(figsize=(10, 7))
for i, f in enumerate(fs, 1):
    t = np.arange(len(signals[f])) / f
    plt.subplot(3, 1, i)
    plt.plot(t, signals[f])
    plt.title(f"Tần số lấy mẫu: {f/1000} kHz")
    plt.xlabel("Thồi gian (s)")
    plt.ylabel("Biên độ")
plt.tight_layout()
plt.show()
