import math

def sum3(x, n):
    if n<=0:
        return math.inf
    tong=0
    for i in range(1, n+1):
        tong+=x**i
    return tong
x=float(input("Nhap so thuc x: "))
n=int(input("Nhap so nguyen n: "))
r=sum3(x, n)
if r==math.inf:
    print("Vui long nhap so n > 0.")
else:
    print(f"Tong la: {r}")
