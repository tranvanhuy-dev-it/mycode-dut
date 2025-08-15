def XULYXULY():
    diem_chuan = float(input("Nhap diem chuan: "))
    while diem_chuan < 0 or diem_chuan > 10:
        print("DIEM CHUAN KHONG HOP LE")
        diem_chuan = float(input("Nhap diem chuan: "))
    diemmon1 = float(input("Nhap diem mon 1: "))
    while diemmon1 < 0 or diemmon1 > 10:
        print("DIEM THI KHONG HOP LE")
        diemmon1 = float(input("Nhap diem mon 1: "))
    diemmon2 = float(input("Nhap diem mon 2: "))
    while diemmon2 < 0 or diemmon2 > 10:
        print("DIEM THI KHONG HOP LE")
        diemmon2 = float(input("Nhap diem mon 2: "))
    diemmon3 = float(input("Nhap diem mon 3: "))
    while diemmon3 < 0 or diemmon3 > 10:
        print("DIEM THI KHONG HOP LE")
        diemmon3 = float(input("Nhap diem mon 3: "))
    khuvuc = input("Nhap khu vuc (A/B/C/X): ").upper()
    doituong = int(input("Nhap doi tuong (0/1/2/3): "))
    if diemmon1 == 0 or diemmon2 == 0 or diemmon3 == 0:
        print("Thi sinh bi rot vi co diem 0 o mon thi.")
        return
    if khuvuc == 'A':
        diemkhuvuc = 2
    elif khuvuc == 'B':
        diemkhuvuc = 1
    elif khuvuc == 'C':
        diemkhuvuc = 0.5
    else:
        diemkhuvuc = 0
    if doituong == 1:
        diemdoituong = 2.5
    elif doituong == 2:
        diemdoituong = 1.5
    elif doituong == 3:
        diemdoituong = 1
    else:
        diemdoituong = 0
    diemtong = diemmon1 + diemmon2 + diemmon3 + diemkhuvuc + diemdoituong
    print(f"Tong diem cua thi sinh: {diemtong}")
    if diemtong >= diem_chuan:
        print("Thi sinh do da truong!")
    else:
        print("Thi sinh bi rot!")
XULYXULY()
