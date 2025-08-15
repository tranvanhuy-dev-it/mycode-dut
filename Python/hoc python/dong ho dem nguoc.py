import time

sec = int(input("Nhap vao thoi gian dem nguoc: "))

while sec >= 0:
    print(f"Con lai {sec} giay")
    time.sleep(1)
    sec -= 1
print("Het gio")