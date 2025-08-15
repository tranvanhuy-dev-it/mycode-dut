def GCD(a,b):
    while b!=0:
        a,b=b,a%b
    return a
def LCM(a,b):
    if a<=0 or b<=0:return 0
    return (a*b)//GCD(a,b)

a=int(input("Nhap so nguyen a: "))
b=int(input("Nhap so nguyen b: "))
r=LCM(a,b)
if r==0:
    print("Vui long nhap hai so nguyen > 0.")
else:
    print(f"Boi chung nho nhat cua {a} va {b} la: {r}")
