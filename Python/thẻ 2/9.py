import math
n = int(input("Nhap mot so nguyen duong n: "))
while n <= 0 or n>100:
    n = int(input("Vui long nhap so nguyen duong: "))
s=0
for i in range(1, n):
    if n%i==0:
        s+=i
if s==n:
    print("YES")
else:
    print("NO")
