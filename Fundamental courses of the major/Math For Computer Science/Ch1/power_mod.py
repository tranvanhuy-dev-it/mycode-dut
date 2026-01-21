def power_mod(a, m, n):
    result = 1
    a = a % n
    while m > 0:
        if m % 2 == 1:
            result = (result * a) % n
        a = (a * a) % n
        m //= 2
    return result


def main():
    a = int(input("Nhap a: "))
    m = int(input("Nhap m: "))
    n = int(input("Nhap n: "))

    print(f"{a}^{m} mod {n} =", power_mod(a, m, n))

if __name__ == "__main__":
    main()
