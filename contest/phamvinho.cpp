#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<long> a(n);
    for (long &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int left = 0;
    int right = 1;
    while (left < n && right < n) {
        if (- a[left] + a[right] <= k) {
            cnt++;
            right++;
        }
        else {
            left++;
        }
    }
    cout << cnt << endl;
    return 0;
}