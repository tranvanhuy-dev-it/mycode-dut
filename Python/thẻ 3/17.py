import math
def fibonacci(n):
    if n<=0:
        return math.inf
    a,b=0,1
    for i in range(2, n+1):
        a,b=b,a+b
    
    if n==1:
        return 1
    elif n==0:
        return 0
    else:
        return b
n=int(input("Nhap so nguyen n: "))
r=fibonacci(n)

if r==math.inf:
    print("Vui long nhap dung.")
else:
    print(f"So Fibonacci thu {n} lala: {r}")
