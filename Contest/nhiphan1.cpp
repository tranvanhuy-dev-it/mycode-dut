#include <iostream>
#define max 100000

using namespace std;

int main() {
    int n, k;
    int A[max];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int key;
    while (k--) {
        cin >> key;
        int l = 1, r = n;
        int pos = -1; 

        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] == key) {
                pos = mid;
                break;
            }
            else if (A[mid] > key) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << pos << "\n";
    }
}
