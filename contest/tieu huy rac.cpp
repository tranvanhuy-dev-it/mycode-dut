#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        int res = 0;

        while (!a.empty()) {
            int weight = a[0];

            if (weight <= c) {
                a.erase(a.begin());
            } else {
                a.erase(a.begin());
                res++;
            }
            for (int &x : a) x *= 2;
        }
        cout << res << '\n';
    }
    return 0;
}
