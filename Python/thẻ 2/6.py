n=int(input("Nhap so nguyen duong n: "))
while n<0 or n>100:
    n=int(input("Vui long nhap so nguyen duong: "))
dem=0
for i in range(1, n+1):
    if n%i==0:
        dem+=1
print(f"{n} co {dem} ưoc!")
