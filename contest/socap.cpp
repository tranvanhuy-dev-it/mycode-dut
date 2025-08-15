#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;
    vector<long> a(n);
    for (long &i : a) {
        cin >> i;
    }
    int cnt = 0;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        if (a[left] + a[right] == x) {
            cnt++;
            left++;
            right--;
        }
        else if (a[left] + a[right] < x) {
            left++;
        }
        else {
            right--;
        }
    }
    cout << cnt << endl;
    return 0;
}