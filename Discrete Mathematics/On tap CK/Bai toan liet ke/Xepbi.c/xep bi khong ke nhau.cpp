#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, m;
vector<int> Max;
vector<int> a;
vector<int> cnt;
int res = 0;

void printArray() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int i) {
    for (int j = 1; j <= m; j++) {
        if (cnt[j] < Max[j] && (i == 0 || a[i - 1] != j)) {
            a[i] = j;
            cnt[j]++;
            if (i == n - 1) {
                res++;
                printArray();
            } else {
                Try(i + 1);
            }
            cnt[j]--;
        }
    }
}

int main() {
    cout << "Nhap so luong mau: ";
    cin >> m;
    Max.resize(m + 1);
    cnt.resize(m + 1, 0);
    n = 0;
    cout << "Nhap " << m << " so bi cua moi mau:\n";
    for (int i = 1; i <= m; i++) {
        cout << "Mau[" << i << "] = ";
        cin >> Max[i];
        n += Max[i];
    }
    a.resize(n);
    Try(0);
    cout << "Tong so cach xep thoa man: " << res << endl;
    return 0;
}

