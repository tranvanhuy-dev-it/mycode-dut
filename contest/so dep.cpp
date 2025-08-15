#include <iostream>
using namespace std;

long long countBeautiful(long long x) {
    return x / 3 + x / 5 + x / 7 
         - x / 15 - x / 21 - x / 35 
         + x / 105;
}

long long findKthBeautiful(long long k) {
    long long l = 1, r = 1e18, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (countBeautiful(mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    long long k;
    cin >> k;
    cout << findKthBeautiful(k) << endl;
    return 0;
}
