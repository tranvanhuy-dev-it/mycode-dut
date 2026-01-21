#include<iostream>
const long long mod = 1000000007;

using namespace std;

unsigned long long fibo(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    unsigned long long f[n + 1];
    f[0] = 0;
    f[1] = 1;
    for (unsigned long long i = 2; i <= n; i++) {
        f[i] = (f[i-1] + f[i-2])%mod;
    }
    return f[n];
}

int main() {

    unsigned long long n;
    cin >> n;
    unsigned long long kq = fibo(n);
    cout << kq << "\n";
    return 0;
}