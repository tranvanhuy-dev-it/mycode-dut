import requests

def doi_tien(from_currency, to_currency, so_tien):
    url = f"https://api.exchangerate.host/convert?from={from_currency}&to={to_currency}&amount={so_tien}"
    response = requests.get(url)
    data = response.json()

    if response.status_code == 200 and "result" in data:
        return data["result"]
    else:
        return None


print("=== MÁY CHUYỂN ĐỔI TIỀN TỆ ===")
from_currency = input("Từ tiền tệ (ví dụ: USD, VND, EUR): ").upper()
to_currency = input("Đổi sang tiền tệ (ví dụ: USD, VND, EUR): ").upper()
so_tien = float(input("Nhập số tiền: "))

ket_qua = doi_tien(from_currency, to_currency, so_tien)

if ket_qua is not None:
    print(f"{so_tien} {from_currency} = {ket_qua:.2f} {to_currency}")
else:
    print("Không lấy được tỷ giá. Vui lòng thử lại.")
