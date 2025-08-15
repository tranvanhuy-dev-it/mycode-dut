def is_perfect(n):
    if n<=1:
        return False
    tong=0
    for i in range(1, n//2+1):
        if n%i==0:
            tong+=i
    return tong==n
def sum_perfect_numbers(n):
    if n<=1:
        return -1
    total=0
    for i in range(2, n+1):
        if is_perfect(i):
            total+=i
    return total if total>0 else -1
n = int(input("Nhap mot so nguyen n: "))
r=sum_perfect_numbers(n)

if r==-1:
    print("Khong tinh duoc tong.")
else:
    print(f"Tong cac so hoan hao tu 1 den {n} la: {r}")
