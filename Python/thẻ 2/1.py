import math
hinh = int(input("Chon hinh muon tinh(chon 1, 2 hoac 3):\n1. Tam giac\n2. Hinh chu nhat\n3. Hinh vuong\n"))
if hinh==1:
    a = float(input("Nhap canh a: "))
    b = float(input("Nhap canh b: "))
    c = float(input("Nhap canh c: "))
    if a+b>c and a+c>b and b+c>a:
        p=(a+b+c)*0.5
        s=math.sqrt(p*(p-a)*(p-b)*(p-c))
        print(f"Chu vi tam giac la: {p*2}")
        print(f"Dien tich tam giac la: {s}")
    else:
        print("Ba canh khong hop le!")
elif hinh==2:
    chieudai=float(input("Nhap chieu dai: "))
    chieurong=float(input("Nhap chieu rong: "))
    chuvi=2*(chieudai+chieurong)
    dientich=chieudai*chieurong
    print(f"Chu vi hinh chu nhat la: {chuvi}")
    print(f"Dien tich hinh chu nhat la: {dientich}")
elif hinh==3:
    a=float(input("Nhap do dai canh: "))
    chuvi=4*a
    dientich=a*a
    print(f"Chu vi hinh vuong la: {chuvi}")
    print(f"Dien tich hinh vuong la: {dientich}")
else:
    print("Vui long chon 1 2 hoac 3")
