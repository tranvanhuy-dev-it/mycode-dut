import math

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def phan_tich_luy_thua(n):
    if is_prime(n):
        print(f"{n} la so nguyen to")
        return [(n, 1)]
    else :
        print(f"{n} khong phai la so nguyen to")
        i = 2
        ket_qua = []

        while i * i <= n:
            dem = 0
            while n % i == 0:
                dem += 1
                n //= i
            if dem > 0:
                ket_qua.append((i, dem))
            i += 1

        if n > 1:
            ket_qua.append((n, 1))

        return ket_qua


def main():
    n = int(input("Nhap vao n: "))
    kq = phan_tich_luy_thua(n)

    print(f"{n} =", end=" ")
    for i in range(len(kq)):
        a, b = kq[i]
        if i > 0:
            print(" * ", end="")
        print(f"{a}^{b}", end="")

if __name__ == "__main__":
    main()
