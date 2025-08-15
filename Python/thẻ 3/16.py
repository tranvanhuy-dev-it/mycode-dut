import math
def sin2(x, e):
    if not (-math.pi<=x<math.pi) or not (0<e<10**-2):
        return 101
    total=0
    term =x
    n=0
    while abs(term)>=e:
        total+=term
        n+=1
        term=((-1)**n * x**(2*n+1))/math.factorial(2*n+1)
    return total
x=float(input("Nhap so thuc x trong doan [-pi, pi]: "))
e=float(input("Nhap do chinh xac e (0 < e < 10^-2): "))
r=sin2(x, e)
if r==101:
    print("Gia tri x phai thuoc doan [-pi, pi] va e phai thoa man 0 < e < 10^-2.")
else:
    print(f"Gia tri cua sin({x}) la: {r}")
