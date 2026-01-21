# Euclid mở rộng: trả về (gcd, x, y) sao cho ax + by = gcd(a, b)
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    d, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return d, x, y


# Giải phương trình ax + by = c
def solve_diophantine(a, b, c):
    d, x0, y0 = extended_gcd(a, b)

    if c % d != 0:
        print("Phuong trinh vo nghiem")
        return

    # Nghiệm riêng
    x0 *= c // d
    y0 *= c // d

    print("Phuong trinh co nghiem")
    print(f"Nghiem rieng: x = {x0}, y = {y0}")

    print("Nghiem tong quat:")
    print(f"x = {x0} + {b//d} * t")
    print(f"y = {y0} - {a//d} * t")
    print("(t la so nguyen)")


def main():
    a = int(input("Nhap a: "))
    b = int(input("Nhap b: "))
    c = int(input("Nhap c: "))

    solve_diophantine(a, b, c)


if __name__ == "__main__":
    main()
