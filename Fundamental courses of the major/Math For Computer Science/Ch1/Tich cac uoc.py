import math

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


def so_luong_uoc(n):
    tsnt = phan_tich_luy_thua(n)
    d = 1
    for _, a in tsnt:
        d *= (a + 1)
    return d


def tich_cac_uoc(n):
    d = so_luong_uoc(n)
    return int(n ** (d / 2)) 


def main():
    n = int(input("Nhap vao n: "))
    print("Tich cac uoc cua", n, "la:", tich_cac_uoc(n))

if __name__ == "__main__":
    main()
