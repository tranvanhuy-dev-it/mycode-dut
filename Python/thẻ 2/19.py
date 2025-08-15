import math
def tinhtohop(n, k):
    return math.factorial(n)//(math.factorial(k)*math.factorial(n-k))
while True:
    try:
        n=int(input("Nhap so nguyen duong n: "))
        k=int(input("Nhap so nguyen k < n: "))
        if n>0 and k>0 and k<n:
            break
        else:
            print("Vui long nhap n va k hop le")
    except ValueError:
        print("Vui long nhap n va k hop le")
r=tinhtohop(n, k)
print(f"To hợp C({n}, {k}) la: {r}")
