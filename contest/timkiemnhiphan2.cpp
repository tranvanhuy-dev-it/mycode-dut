#include <iostream>
using namespace std;

long long count(long long x, long long n, long long m) {
    long long cnt = 0;
    for (long long i = 1; i <= n; ++i) {
        cnt += min(m, x / i);
    }
    return cnt;
}

long long find(long long n, long long m, long long k) {
    long long l = 1, r = n * m, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (count(mid, n, m) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    cout << find(n, m, k) << endl;
    return 0;
}
