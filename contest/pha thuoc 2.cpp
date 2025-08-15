#include<bits/stdc++.h>

using namespace std;

int main() {

    long n, k;
    cin >> n >> k;

    vector<long> a(n);
    for (long &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    int res = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        while (a[right] - a[left] > k) {
            ++left;
        }
        res = max(res, right - left + 1);
    }

    cout << res << "\n";

    return 0;
}