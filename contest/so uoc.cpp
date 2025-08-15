#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long res[N];

void U() {
    for (long long i = 1; i < N; ++i) {
        for (long long j = i; j < N; j += i) {
            res[j] ++;
        }
    }
}

int main() {

    long t;
    cin >> t;
    U();
    while (t--) {
        long long n;
        cin >> n;
        cout << res[n] << "\n";
    }
    return 0;
}