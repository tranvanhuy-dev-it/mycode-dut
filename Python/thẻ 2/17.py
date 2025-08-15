import math
def tinhbieuthuc(n):
    r=1
    for i in range(n, 0, -1):
        r=math.pow(i, 1 / r)
    return r
n=int(input("Nhap mot so nguyen duong n: "))
while n<=0 or n>100:
    n=int(input("Vui long nhap so nguyen duong: "))
result = tinhbieuthuc(n)
print(f"Gia tri cua bieu thuc la: {result:.6f}")
