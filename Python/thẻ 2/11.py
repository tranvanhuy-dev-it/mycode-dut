import math
n=int(input("Nhap mot so nguyen duong n: "))
while n<=0 or n>100:
    n=int(input("Vui long nhap so nguyen duong: "))
if n%2==0:
    s=n//2
else:
    s=-(n+1)//2
print(f"Tong la: {s}")
