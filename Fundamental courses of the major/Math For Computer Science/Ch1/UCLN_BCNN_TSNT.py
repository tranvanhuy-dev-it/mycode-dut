import math

# Phân tích n thành thừa số nguyên tố dạng dict {prime: exponent}
def phan_tich_luy_thua(n):
    ts = {}
    i = 2
    while i * i <= n:
        while n % i == 0:
            ts[i] = ts.get(i, 0) + 1
            n //= i
        i += 1
    if n > 1:
        ts[n] = ts.get(n, 0) + 1
    return ts

# In dạng lũy thừa: 2^2 * 3
def in_luy_thua(ts):
    kq = []
    for p in ts:
        if ts[p] == 1:
            kq.append(str(p))
        else:
            kq.append(f"{p}^{ts[p]}")
    return " * ".join(kq)

# UCLN dùng thừa số nguyên tố
def ucln_tsnt(a, b):
    fa = phan_tich_luy_thua(a)
    fb = phan_tich_luy_thua(b)
    ucln = 1
    for p in fa:
        if p in fb:
            ucln *= p ** min(fa[p], fb[p])
    return ucln

# BCNN dùng thừa số nguyên tố
def bcnn_tsnt(a, b):
    fa = phan_tich_luy_thua(a)
    fb = phan_tich_luy_thua(b)
    bcnn = 1
    for p in set(fa) | set(fb):
        bcnn *= p ** max(fa.get(p, 0), fb.get(p, 0))
    return bcnn


def main():
    a = int(input("Nhap a: "))
    b = int(input("Nhap b: "))

    fa = phan_tich_luy_thua(a)
    fb = phan_tich_luy_thua(b)

    print("\nPhan tich thua so nguyen to:")
    print(f"{a} =", in_luy_thua(fa))
    print(f"{b} =", in_luy_thua(fb))

    print("\nKet qua:")
    print("UCLN =", ucln_tsnt(a, b))
    print("BCNN =", bcnn_tsnt(a, b))


if __name__ == "__main__":
    main()
