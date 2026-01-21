import sounddevice as sd
import numpy as np
import matplotlib.pyplot as plt

fs = int(input('Nhập vào tần số lấy mẫu (Hz): '))

recorded = []
def callback(indata, frames, time, status):
    recorded.append(indata.copy())
with sd.InputStream(samplerate=fs, channels=1, dtype='int16', callback=callback):
    print("Đang ghi âm... Nhấn ENTER để dừng ghi.", end = '')
    input()

signal = np.concatenate(recorded, axis=0).flatten()
signal = signal
print("Ghi âm hoàn tất.")

print("Phát lại bản ghi...")
sd.play(signal, fs)
sd.wait()
print('Kích thước mẫu:', len(signal))

plt.figure(figsize=(10, 4))
t = np.arange(len(signal)) / fs
plt.plot(t, signal)
plt.title(f'Tín hiệu âm thanh đã ghi (Tần số lấy mẫu: {fs/1000} kHz)')
plt.xlabel('Thời gian (s)')
plt.ylabel('Biên độ')
plt.tight_layout()
plt.show()


