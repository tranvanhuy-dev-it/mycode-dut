def sang_so_nguyen_to(n):
    if n < 2:
        return []

    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    primes = []
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)

    return primes


def main():
    n = int(input("Nhap vao n: "))
    primes = sang_so_nguyen_to(n)
    print(f"Cac so nguyen to <= {n} la:")
    print(primes)


if __name__ == "__main__":
    main()
