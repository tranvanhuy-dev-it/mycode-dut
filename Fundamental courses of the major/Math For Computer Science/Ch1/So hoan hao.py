import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def find_perfect_numbers(n):
    p = 2
    while True:
        mersenne_prime = 2**p - 1
        if is_prime(mersenne_prime):
            kq = (2**(p - 1)) * mersenne_prime
            if kq > n:
                break
            print(f"{kq}", end=' ')
        p += 1

def main():
    n = int(input("Nhập vào số n: "))
    print(f"Các số hoàn hảo từ 1 đến {n} là:", end=' ')
    find_perfect_numbers(n)


if __name__ == "__main__":
    main()
