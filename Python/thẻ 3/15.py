import math

def sin1(x, n):
    if not (-math.pi<=x<=math.pi) or n<=0:
        return 101
    tong=0
    for i in range(n+1):
        tong+=((-1)**i*(x**(2*i+1)))/math.factorial(2*i+1)
    return tong
x=float(input("Nhap so thuc x trong doan [-pi, pi]: "))
n=int(input("Nhap so nguyen n: "))
r=sin1(x, n)
if r==101:
    print("Gia tri x phai thuoc doan [-pi, pi] hoac n phai > 0.")
else:
    print(f"Gia tri cua bieu thuc la: {r}")
