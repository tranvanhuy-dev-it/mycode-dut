import math
def giaiphuongtrinh(a, b, c):
    delta=b**2-4*a*c
    if delta > 0:
        x1=(-b + math.sqrt(delta))/(2*a)
        x2=(-b - math.sqrt(delta))/(2*a)
        return f"Phuong trinh co hai nghiem phan biet: x1 = {x1} va x2 = {x2}"
    elif delta==0:
        x=-b/(2*a)
        return f"Phuong trinh co nghiem kep: x = {x}"
    else:
        return "Phuong trinh vo nghiem."
def main():
    a=float(input("Nhap he so a: "))
    b=float(input("Nhap he so b: "))
    c=float(input("Nhap he so c: "))
    if a==0:
        print("Vui long nhap a khac 0!")
    else:
        r=giaiphuongtrinh(a, b, c)
        print(r)
if __name__ == "__main__":
    main()
