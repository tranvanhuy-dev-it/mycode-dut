def find_element_n(n):
    if n<=0:
        return -1
    F1=1
    F2=2
    if n==1:
        return F1
    elif n==2:
        return F2
    for i in range(3,n+1):
        Fn=5*F2+3*F1
        F1=F2
        F2=Fn
    return F2
n=int(input("Nhap so nguyen n: "))
r=find_element_n(n)
if r==-1:
    print("Vui long nhap so n > 0.")
else:
    print(f"Phan tu thu {n} cua day la: {r}")
