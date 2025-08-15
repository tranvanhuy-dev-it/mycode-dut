def tinhtich(n):
    if n%2!=0:
        tich=1
        for i in range(1,n+1,2):
            tich*=i
    else:
        tich=1
        for i in range(2,n+1,2):
            tich*=i
    return tich

n=int(input("Nhap mot so nguyen duong n > 0: "))
while n<=0:
    n=int(input("Vui long nhap n > 0: "))
r=tinhtich(n)
print(f"Gia tri cua bieu thuc S la: {r}")
