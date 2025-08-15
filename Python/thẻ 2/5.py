n=int(input("Nhap vao so nguyen duong n: "))
while n<n:
    print("Vui long nhap vao so nguyen duong: ")
print(f"Cac chu so cua {n} la: ", end="")
chuso = [int(chuso) for chuso in str(n)]
print(", ".join(map(str, chuso)))
