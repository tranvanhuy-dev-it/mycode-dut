def trungbinhcong(n):
    tong=0
    dem=0
    for i in range(n):
        x = int(input(f"Nhap so thu {i+1}: "))
        if x%2==0:
            tong+=x
            dem+=1
    if dem==0:
        return 0
    return tong/dem
n=int(input("Nhap so nguyen duong: "))
while n<=0:
    n=int(input("Vui long nhap so nguyen duongduong: "))
r=trungbinhcong(n)
if r==0:
    print("Khong co so chan.")
else:
    print(f"Trung binh cong cua cac so chan la: {r}")
