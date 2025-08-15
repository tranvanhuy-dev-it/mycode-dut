import math
def tinhbieuthuc(x, n):
    S = 0
    for i in range(n + 1):
        S += ((-1)**i) * (x**(2*i + 1)) / math.factorial(2*i + 1)
    return S
while True:
    try:
        x=float(input("Nhap so thuc x: "))
        break
    except ValueError:
        print("Vui long nhap so thuc!")
while True:
    try:
        n=int(input("Nhap so nguyen n: "))
        if n>=0:
            break
        else:
            print("Vui long nhap so nguyen duong!")
    except ValueError:
        print("Vui long nhap so nguyen hop le!")
r=tinhbieuthuc(x, n)
print(f"Gia tri cua bieu thuc la: {r:.6f}")
