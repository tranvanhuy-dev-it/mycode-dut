//O(logn)
#include <iostream>
typedef long long ll;

using namespace std;

//tinh modulo
ll mod_pow(ll x, ll n, ll mod) {
    if (n == 0) return 1 % mod;
    ll u = mod_pow(x, n / 2, mod);
    u = (u * u) % mod;
    if (n % 2 == 1) {
        u = (u * x) % mod;
    }
    return u;
}

int main() {

    ll x, n, mod;
    mod = 1e9 + 7;
    cout << "Nhap co so x: ";
    cin >> x;
    cout << "Nhap so mu n: ";
    cin >> n;
    ll result = mod_pow(x, n, mod);
    cout << x << "^" << n << " mod " << mod << " = " << result << endl;
    return 0;
}