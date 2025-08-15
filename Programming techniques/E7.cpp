#include <iostream>
#include <string>

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là chữ số chẵn hay không
bool xyly(char c) {
    // Chuyển ký tự sang số nguyên
    int digit = c - '0';  // '0' có giá trị ASCII là 48, trừ đi để có giá trị số
    return digit % 2 == 0;  // Kiểm tra xem chữ số có phải là số chẵn không
}

int main() {
    string number;
    cin >> number;  // Nhập vào chuỗi số
    int l = number.size();  // Độ dài chuỗi

    // Kiểm tra từng ký tự trong chuỗi
    bool hasEven = false;  // Biến để kiểm tra có số chẵn không
    for (int i = 0; i < l; i++) {
        if (xyly(number[i])) {  // Nếu tìm thấy chữ số chẵn
            hasEven = true;
            break;  // Dừng vòng lặp khi tìm thấy số chẵn
        }
    }

    // In kết quả
    if (hasEven) {
        cout << "YES" << endl;  // Có số chẵn
    } else {
        cout << "NO" << endl;   // Không có số chẵn
    }

    return 0;
}
