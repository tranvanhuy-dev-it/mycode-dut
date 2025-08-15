def sum1(n):
    if n<=0:
        return -1
    tong=0
    for i in range(1, n+1):
        tong+=i**3
    return tong
n=int(input("Nhap mot so nguyen n:"))
r=sum1(n)

if r==-1:
    print("Vui long nhap dung: ")
else:
    print(f"Tong gia tri cua bieu thuc 13+23+...+n3 la: {r}")
