n=int(input("Nhap mot so nguyen duong n: "))
while n<=0:
    n=int(input("Vui long nhap so nguyen duong: "))
tong=0
for i in range(1, n+1):
    if n%i==0:
        tong+=i
print(f"So uoc cua {n} la: {tong}")
