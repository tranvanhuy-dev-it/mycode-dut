n = int(input("Nhap mot so nguyen duong n: "))
while n<=0 or n>100:
    n = int(input("Vui long nhap so nguyen duong: "))
def snt(n):
    if n<=1:
        return False
    else:
        for i in range(2, n):
            if n%i==0:
                return False
    return True
if snt(n)==True:
    print("YES")
else:
    print("NO")

