def tinhtientaxi(khoangcach):
    if khoangcach<=1000:
        return 5000
    elif khoangcach<=30000:
        return 5000+((khoangcach-1000)//200)*1000
    else:
        tien=5000+((30000-1000)//200)*1000
        tien+=((khoangcach-30000)//1000)*3000
        if khoangcach%1000!=0:
            tien+=3000
        return tien
khoang_cach=int(input("Nhap khoang cach (m): "))
if khoang_cach<=0:
    print("Khoang cach phai lon hon 0.")
else:
    tien=tinhtientaxi(khoang_cach)
    print(f"Tong tien phai tra: {tien} VND")
