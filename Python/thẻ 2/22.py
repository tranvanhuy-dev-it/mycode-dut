n=int(input("Nhap mot so nguyen duong n: "))
while n<=0:
    n=int(input("Vui long nhap so nguyen duong: "))
m=0
tongm=0
while tongm+(m+1)<n:
    m+=1
    tongm+=m
print(f"m la: {m}")
