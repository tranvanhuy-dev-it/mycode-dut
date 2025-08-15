def is_prime(n):
    if n<=1:
        return False
    for i in range(2, int(n ** 0.5)+1):
        if n%i==0:
            return False
    return True
def sum_prime_numbers(n):
    if n<=1:
        return -1
    tong=0
    for i in range(2, n+1):
        if is_prime(i):
            tong+=i
    return tong
n=int(input("Nhap so nguyen n: "))
r=sum_prime_numbers(n)
if r==-1:
    print("Vui long nhap dung! ")
else:
    print(f"Tong cac so nguyen to tu 1 den {n} la: {r}")
