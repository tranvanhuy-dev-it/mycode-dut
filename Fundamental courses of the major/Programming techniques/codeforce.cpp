#include <iostream>
#include <vector>
using namespace std;

// Hàm xử lý từng test case
int xuly(const vector<int>& A, int n, int k) {
    for (int i = 0; i < n; ++i) {
        bool can_win = false;
        for (int j = 0; j < n; ++j) {
            if (i != j && abs(A[i] - A[j]) % k != 0) {
                can_win = true; // Tồn tại một j khác i sao cho người chơi 1 có thể thắng
                break;
            }
        }
        if (can_win) {
            return i + 1; // Trả về chỉ số 1-based
        }
    }
    return -1; // Không thể thắng
}

int main() {
    int t; // Số lượng test case
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        int result = xuly(A, n, k);

        if (result != -1) {
            cout << "YES\n" << result << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
