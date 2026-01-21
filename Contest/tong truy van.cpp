#include<iostream>

using namespace std;

int main() {

    int n, q;
    cin >> n >> q;

    unsigned long A[100000], prefix[100000];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + A[i];
    }
    int l, r;
    while (q--) {
        cin >> l >> r;
        unsigned long sum = 0;
        sum = prefix[r] - prefix[l - 1];
        cout << sum << "\n";
    }


    return 0;
}