import math
def kiemtra(xC, yC, R, xM, yM):
    khoangcach=math.sqrt((xM - xC)**2 + (yM - yC)**2)
    if khoangcach<R:
        return "M nam trong duong tron"
    elif khoangcach==R:
        return "M nam tren duong tron"
    else:
        return "M nam ngoai duong tron"
def nhap():
    xC=float(input("Nhap toa do x cua tam C: "))
    yC=float(input("Nhap toa do y cua tam C: "))
    R=float(input("Nhap ban kinh R cua duong tron: "))
    xM=float(input("Nhap toa do x cua diem M: "))
    yM=float(input("Nhap toa do y cua diem M: "))
    r=kiemtra(xC, yC, R, xM, yM)
    print(r)
nhap()
