def is_perfect(n):
    if n<=1:
        return False
    tong=0
    for i in range(1, n // 2 + 1):
        if n%i == 0:
            tong+=i
    return tong==n
def average_perfect_numbers(n):
    if n<=1:
        return -1
    tong=0
    dem=0
    for i in range(2, n+1):
        if is_perfect(i):
            tong+=i
            dem+=1
    if dem==0:
        return -1
    return tong/dem
n = int(input("Nhap so nguyen duong n:"))
r=average_perfect_numbers(n)
if r==-1:
    print("errorerror")
else:
    print(f"Trung binh cong {n} la:{r}")
