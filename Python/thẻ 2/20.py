while True:
    try:
        n = int(input("Nhap so dong n (0 < n ≤ 100): "))
        k = int(input("Nhap so dau sao k (0 < k ≤ 100): "))
        if 0<n<=100 and 0<k<=100:
            break
        else:
            print("vui long nhap n va k sao cho 0 < n, k ≤ 100!")
    except ValueError:
        print("Vui long nhap gia tri hop le!")
for i in range(n):
    print('*' * k)
for i in range(n):
    print('*' * i)
