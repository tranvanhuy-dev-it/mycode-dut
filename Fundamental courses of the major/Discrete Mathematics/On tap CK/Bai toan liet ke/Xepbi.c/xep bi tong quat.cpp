#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> limit;
vector<int> a;
vector<int> cnt;
int res = 0;

void printArray() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool isValid(int pos, int color) {
    if (pos >= k-1) {
        bool same = true;
        for (int i = pos-1; i >= pos-k+1; i--) {
            if (a[i] != color) {
                same = false;
                break;
            }
        }
        if (same) return false;
    }
    return true;
}

void Try(int i) {
    for (int j = 1; j <= m; j++) {
        if (cnt[j] < limit[j] && isValid(i, j)) {
            a[i] = j;
            cnt[j]++;
            if (i == n - 1) {
                res++;
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
    cout << "Nhap gioi han k (khong co k bi cung mau ke nhau): ";
    cin >> k;
    
    limit.resize(m + 1);
    cnt.resize(m + 1, 0);
    n = 0;
    
    cout << "Nhap so luong bi cho moi mau:\n";
    for (int i = 1; i <= m; i++) {
        cout << "Mau[" << i << "] = ";
        cin >> limit[i];
        n += limit[i];
    }
    
    a.resize(n);
    Try(0);
    cout << "Tong so cach xep thoa man: " << res << endl;
    return 0;
}