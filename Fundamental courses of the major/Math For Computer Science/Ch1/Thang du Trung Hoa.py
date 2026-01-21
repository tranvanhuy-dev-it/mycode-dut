# Euclid mở rộng
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    d, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return d, x, y


# Nghịch đảo modulo
def mod_inverse(a, m):
    d, x, _ = extended_gcd(a, m)
    if d != 1:
        return None
    return x % m


# Giải hệ thặng dư Trung Hoa
def chinese_remainder(a, m):
    M = 1
    for mi in m:
        M *= mi

    x = 0
    for i in range(len(a)):
        Mi = M // m[i]
        yi = mod_inverse(Mi, m[i])
        x += a[i] * Mi * yi

    return x % M, M


def main():
    n = int(input("Nhap so phuong trinh: "))

    a = []
    m = []

    print("\nNhap cac gia tri a:")
    for i in range(n):
        a.append(int(input(f"a[{i+1}] = ")))

    print("\nNhap cac gia tri m:")
    for i in range(n):
        m.append(int(input(f"m[{i+1}] = ")))

    x, M = chinese_remainder(a, m)

    print("\nNghiem cua he:")
    print(f"x ≡ {x} (mod {M})")


if __name__ == "__main__":
    main()
