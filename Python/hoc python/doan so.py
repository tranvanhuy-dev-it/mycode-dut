import random

scr = random.randint(1, 100)

print("TRO CHOI DOAN SO")
print("Toi da chon mot so tu 1 den 100, ban hay doan do la so nao!")

while 1:
    ans = int(input("Nhap vao du doan cua ban: "))
    if ans > scr:
        print("Nho hon!")
    elif ans < scr:
        print("Lon hon!")
    else:
        print(f"Dung roi, do la {scr}")
        break