#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//gcd
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

//power mod
ll powerMod(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

//kiem tra so nguyen to
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

//phan tich thua so nguyen to
map<ll, ll> prime_factors(ll n) {
    map<ll, ll> factors;
    if (n <= 1) {
        return factors;
    }
    ll i = 2;
    while (i * i <= n) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
        i++;
    }
    if (n >= 2) {
        factors[n] = 1;
    }
    return factors;
}

//tim so cac so nguyen to cung nhau
ll phi(ll n) {
    map<ll, ll> factors = prime_factors(n);
    ll result = 1;

    for (auto x : factors) {
        ll p = x.first;
        ll k = x.second;

        ll term = 1;
        for (int i = 1; i < k; i++)
            term *= p;          // p^(k-1)

        result *= (p - 1) * term;
    }
    return result;
}


/* ===============================
   Fermat nhỏ
   Điều kiện: m là số nguyên tố
================================ */
ll fermat(ll x, ll k, ll m) {
    return powerMod(x, k % (m - 1), m);
}

/* ===============================
   Euler
   Điều kiện: gcd(x, m) = 1
================================ */
ll euler(ll x, ll k, ll m) {
    ll phi_m = phi(m);
    return powerMod(x, k % phi_m, m);
}

/* ===============================
   MAIN
================================ */
int main() {
    ll x, k, m;
    cout << "Nhap x, k, m: ";
    cin >> x >> k >> m;

    if (gcd(x, m) != 1) {
        cout << "x va m khong nguyen to cung nhau -> khong ap dung duoc!\n";
        return 0;
    }

    cout << "\n--- Ket qua ---\n";

    if (isPrime(m)) {
        cout << "m la so nguyen to\n";
        cout << "Dung dinh ly Fermat:\n";
        cout << "x^k mod m = " << fermat(x, k, m) << endl;
    } else {
        cout << "m KHONG la so nguyen to\n";
        cout << "Dung dinh ly Euler:\n";
        cout << "x^k mod m = " << euler(x, k, m) << endl;
    }

    return 0;
}
