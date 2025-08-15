def is_perfect(n):
    if n<=1:
        return False
    t=0
    for i in range(1, n//2+1):
        if n%i==0:
            t+=i
    return t==n
n=int(input("Nhap so nguyen n: "))
if is_perfect(n):
    print(f"{n} la so hoan hao.")
else:
    print(f"{n} khong la so hoan hao.")
