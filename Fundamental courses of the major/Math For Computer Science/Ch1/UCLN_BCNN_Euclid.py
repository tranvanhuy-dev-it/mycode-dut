def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return abs(a)


def lcm(a, b):
    return abs(a * b) // gcd(a, b)


def main():
    a = int(input("Nhap a: "))
    b = int(input("Nhap b: "))

    print("UCLN =", gcd(a, b))
    print("BCNN =", lcm(a, b))


if __name__ == "__main__":
    main()
