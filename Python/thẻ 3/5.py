def INPUT():
    n=int(input("Nhap mot so nguyen duong: "))
    while n<=0:
        n=int(input("Vui long nhap so nguyen duong: "))
    return n
n=INPUT()
print(f"So nguyen duong thoa man yeu cau de baibai")
