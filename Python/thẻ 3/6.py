def is_prime(n):
    if n<=1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True

n=int(input("Nhap mot so nguyenn: "))
if is_prime(n):
    print(f"{n}la so nguyen to.")
else:
    print(f"{n}khong la so nguyen to.")
