def GCD(a,b):
    if a<=0 or b<=0:
        return 0
    while b!=0:
        a,b=b,a%b
    return a
a=int(input("Nhap so nguyen a: "))
b=int(input("Nhap so nguyen b: "))
r=GCD(a,b)
if r==0:
    print("Vui long nhap hai so nguyen > 0.")
else:
    print(f"Uoc chung lon nhat cua {a} va {b} la: {r}")
