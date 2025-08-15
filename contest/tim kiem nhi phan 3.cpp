#include<iostream>

using namespace std;

int main() {

    long long n, q, A[100000];
    cin >> n >> q; 
    for (int i = 1; i <= n; i++) { 
        cin >> A[i];
    }

    int key;
    while (q--) {
        cin >> key;
        int l = 1, r = n;
        int res = -1;
        while (r >= l) {
            int mid = (l + r) / 2;
            if (A[mid] <= key) {
                res = mid;
                l = mid + 1;
            }
            else if (A[mid] > key) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
