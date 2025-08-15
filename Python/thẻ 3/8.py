def is_prime(n):
    if n<=1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            return False
    return True
def average_prime_numbers(n):
    if n<=1:
        return -1
    prime_numbers=[]
    for i in range(2, n+1):
        if is_prime(i):
            prime_numbers.append(i)
    if len(prime_numbers)==0:
        return
    avg=sum(prime_numbers)/len(prime_numbers)
    return avg
n=int(input("Nhap so nguyen n: "))
r=average_prime_numbers(n)
if r==-1:
    print("Khong tinh duoc trung binh cong, hay nhap lai n")
else:
    print(f"Trung binh cong cua cac so nguyen to tu 1 den {n} la: {r:.2f}")
