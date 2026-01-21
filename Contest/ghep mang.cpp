#include<bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long n;
    cin >> n;

    vector<long> a(n),b(n);
    for (long &x : a) {
        cin >> x;
    }

    for (long &x : b) {
        cin >> x;
    }

    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());

    for (long x : a) {
        cout << x << " ";
    }
    return 0;
}