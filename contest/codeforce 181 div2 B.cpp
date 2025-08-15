#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long a, b, k;
        cin >> a >> b >> k;

        unsigned long long A = (a + k - 1) / k;
        unsigned long long B = (b + k - 1) / k;

        unsigned long long steps = max(A, B);

        unsigned long long max_pairs;
        if (k <= (unsigned long long)1e9) {
            max_pairs = (k + 1) * (k + 1);
        } else {
            max_pairs = ULLONG_MAX;
        }

        unsigned long long res = min(steps, max_pairs);
        cout << res << '\n';
    }
    return 0;
}
