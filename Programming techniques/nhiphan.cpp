#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[100], i = 0;

    if (n == 0) {
        cout << "0";
    } else {
        while (n != 0) {
            A[i] = n % 2; // Lưu phần dư vào mảng
            n = n / 2;
            i++;
        }
        for (int j = i - 1; j >= 0; j--) { // In mảng ngược từ i-1 về 0
            cout << A[j];
        }
        cout << endl; // Xuống dòng sau khi in xong
    }
    return 0;
}
