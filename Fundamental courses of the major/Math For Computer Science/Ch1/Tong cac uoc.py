import math

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


def phan_tich_luy_thua(n):
    i = 2
    kq = []
    while i * i <= n:
        dem = 0
        while n % i == 0:
            dem += 1
            n //= i
        if dem > 0:
            kq.append((i, dem))
        i += 1
    if n > 1:
        kq.append((n, 1))
    return kq


def tong_cac_uoc(n):
    if n == 1:
        return 1

    if is_prime(n):
        return 1 + n

    tsnt = phan_tich_luy_thua(n)
    tong = 1

    for p, a in tsnt:
        tong *= (p**(a + 1) - 1) // (p - 1)

    return tong


def main():
    n = int(input("Nhap vao n: "))

    print("Tong cac uoc cua", n, "la:", tong_cac_uoc(n))

if __name__ == "__main__":
    main()
