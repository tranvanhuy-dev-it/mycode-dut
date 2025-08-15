def xuly():
    score = float(input("Nhap diem thi: "))
    if score < 0 or score > 10:
        print("Diem nhap vao khong hop le!")
    elif score < 4:
        print("Kem")
    elif score < 5:
        print("Yeu")
    elif score < 6:
        print("Trung binh")
    elif score < 8:
        print("Kha")
    else:
        print("Gioi")
xuly()
