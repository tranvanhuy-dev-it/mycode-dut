def xuly(a, b):
    if a==0:
        if b==0:
            return "Phuong trinh vo so nghiem."
        else:
            return "Phuong trinh vo nghiem."
    else:
        x=-b/a
        return f"Nghiem cua phuong trinh la: x = {x}"

def main():
    a=float(input("Nhap he so a: "))
    b=float(input("Nhap he so b: "))
    r=xuly(a, b)
    print(r)
if __name__ == "__main__":
    main()
