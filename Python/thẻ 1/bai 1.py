a=float(input("Nhap so thu nhat: "))
b=float(input("Nhap so thu hai: "))
tinhtong=a+b
tinhhieu=a-b
tinhtich=a*b
if b!=0:
    tinhthuong=a/b
else:
    tinhthuong = "KHONG TINH DUOC"
print(f"Tong cua {a} va {b} la: {tinhtong}")
print(f"Hieu cua {a} va {b} la: {tinhhieu}")
print(f"Tiich cua {a} va {b} la: {tinhtich}")
print(f"Thuong cua {a} va {b} la: {tinhthuong}")
