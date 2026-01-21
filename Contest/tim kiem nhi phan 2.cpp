#include <iostream>
#define MAX 100005

using namespace std;

int A[MAX];

int find_first_occurrence(int n, int x) {
    int l = 1, r = n;
    int res = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (A[mid] == x) {
            res = mid;      
            r = mid - 1;   
        } else if (A[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    while (q--) {
        int x;
        cin >> x;
        int ans = find_first_occurrence(n, x);
        cout << ans << "\n";
    }

    return 0;
}
