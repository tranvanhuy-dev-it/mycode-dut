import math

def triangle_area(a, b, c):
    if a+b>c and a+c>b and b+c>a:
        p = (a+b+c)/2
        area = math.sqrt(p*(p-a)*(p-b)*(p-c))
        return area
    else:
        return -1
a=float(input("Nhap canh a: "))
b=float(input("Nhap canh b: "))
c=float(input("Nhap canh c: "))
r=triangle_area(a, b, c)
if r==-1:
    print("Ba canh khong tao thanh mot tam giac")
else:
    print(f"Dien tich tam giac la: {r}")
