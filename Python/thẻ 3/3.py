def is_triangle(a,b,c):
    if a+b>c and a+c>b and b+c>a:
        return True
    else:
        return False
a=float(input("Nhap canh a: "))
b=float(input("Nhap canh b: "))
c=float(input("Nhap canh c: "))
if is_triangle(a,b,c)==True:
    print("True")
else:
    print("False")
