n=int(input("Nhap mot so nguyen duong n: "))
while n<=0:
    n=int(input("Vui long nhap so nguyen duong: "))
a=0
b=1
print(f"{n} so nguyen duong dau tien la:")
for i in range(n):
    print(a, end=" ")
    a, b = b, a + b
