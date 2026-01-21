import math 

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def main():
    n = int(input("Nhap vao n: "))
    if is_prime(n):
        print(f"{n} la so nguyen to")
    else:
        print(f"{n} khong phai la so nguyen to")

if __name__ == "__main__":
    main()
