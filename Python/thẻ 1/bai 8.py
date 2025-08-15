def xuly(day, month, year):
    if year<1900 or year>2050:
        return False
    if month<1 or month>12:
        return False
    if day<1 or day>31:
        return False
    if month in [4, 6, 9, 11] and day>30:
        return False
    if month==2:
        if (year%4==0 and year%100!=0) or (year%400==0):
            if day>29:
                return False
        else:
            if day>28:
                return False
    return True
def nhap():
    day=int(input("Nhap ngay: "))
    month=int(input("Nhap thang: "))
    year=int(input("Nhap nam: "))
    while not (1900<year<2050):
        print("VUI LONG NHAP NAM")
        year=int(input("Nhap nam: "))
    if xuly(day, month, year):
        print(f"Ngay {day}/{month}/{year} hop le.")
    else:
        print(f"Ngay {day}/{month}/{year} khong hop le.")
nhap()
