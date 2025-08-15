import math
def tamgiac(a,b,c):
    return a+b>c and a+c>b and b+c>a
def loaitamgiac(a,b,c):
    if a==b==c:
        return "Tam giac deu"
    elif a==b or b==c or a==c:
        return "Tam giac can"
    else:
        return "Tam giac thuong"
def dientichtamgiac(a,b,c):
    s=(a+b+c)/2
    area=math.sqrt(s*(s-a)*(s-b)*(s-c))
    return area
def main():
    a=int(input("Nhap canh a: "))
    b=int(input("Nhap canh b: "))
    c=int(input("Nhap canh c: "))
    if tamgiac(a,b,c):
        print(f"Tam giac hop le!")
        print(f"Loai tam giac: {loaitamgiac(a,b,c)}")
        cv=a+b+c
        dt=dientichtamgiac(a,b,c)
        print(f"Chu vi tam giac: {cv}")
        print(f"Dien tich tam giac: {dt}")
    else:
        print("Ba canh khong hop le, khong tao thanh tam giac!")
if __name__ == "__main__":
    main()
