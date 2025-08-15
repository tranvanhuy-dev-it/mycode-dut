import math

def sum2(n):
    if n<=0:
        return math.inf
    tong=0
    for i in range(1, n+1):
        if i%2==0:
            tong+=i
        else:
            tong-=i
    return tong
n=int(input("Nhap so nguyen n:"))
r=sum2(n)
if r==math.inf:
    print("Vui long nhap so n > 0.")
else:
    print(f"Tong gia tri cua bieu thuc -1+2-3+4-...+(-1)^n * n la: {r}")
