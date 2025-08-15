a=float(input("Nhap a: "))
b=float(input("Nhap b: "))
c=float(input("Nhap c: "))
d=float(input("Nhap d: "))
e=float(input("Nhap e: "))
f=float(input("Nhap f: "))
D=a*e-b*d
D1=c*e-b*f
D2=a*f-c*d
if D!=0:
    x=D1/D
    y=D2/D
    print(f"Phuong trinh co nghiem: x = {x}, y = {y}")
else:
    print("He phuong trinh vo nghiem hoac co vo so nghiem.")
