import math
xA, yA = map(float, input("Nhap toa do diem A: ").split())
xB, yB = map(float, input("Nhap toa do diem B: ").split())
if xA==xB and yA==yB:
    d=0
else:
    d=math.sqrt((xB - xA)**2+(yB - yA)**2)
cat=(xA * xB < 0) or (xA == 0 or xB == 0)
if xA == 0 and xB == 0:
    cat = True
print(f"Do dai doan thang AB la: {d:.6f}")
if cat:
    print("AB cat truc tung.")
else:
    print("AB khong cat truc tung.")
