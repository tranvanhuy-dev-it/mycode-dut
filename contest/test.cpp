#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        bool ok = (b % 2 == n % 2) && (a <= b || a % 2 == n % 2);
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
