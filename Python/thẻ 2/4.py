n = int(input("Nhap so nguyen duong n: "))
while n <= 0:
    n = int(input("Vui long nhap so nguyen duong: "))
print("Cac so tu 1 den n la:")
for i in range(1, n + 1):
    print(i, end=" ")
print()
print("Cac so chan la:")
for i in range(1, n+1):
    if i%2==0:
        print(i, end=" ")
print()
print("Cac so le khong chia het cho 3 la:")
for i in range(1, n+1):
    if i%2!=0:
        if i%3!=0:
            print(i, end=" ")
print()
