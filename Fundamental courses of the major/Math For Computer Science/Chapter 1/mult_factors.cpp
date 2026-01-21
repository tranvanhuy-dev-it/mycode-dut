//chu y voi n rat lon se bi tran so
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

const long long MOD = 1000000007;

//modulo
long long power_mod(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

//phan tich thua so nguyen to
map<long long, long long> prime_factors(long long n) {
    map<long long, long long> factors;
    if (n <= 1) {
        return factors;
    }
    long long i = 2;
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

//so cac uoc
long long number_factors(long long n) {
    map<long long, long long> factors = prime_factors(n);
    long long cnt = 1;
    for (auto x : factors) {
        cnt *= (x.second + 1);
    }
    return cnt;
}

//tich cac uoc
long long mult_factors(long long n) {
    map<long long, long long> factors = prime_factors(n);

    long long product = 1;
    long long d = 1; 

    for (auto x : factors) {
        long long p = x.first;
        long long e = x.second;


        long long val = power_mod(p, e * (e + 1) / 2);

        product = power_mod(product, e + 1);
        product = product * power_mod(val, d) % MOD;

        d = d * (e + 1) % (MOD - 1);
    }
    return product;
}

int main() {
    long long n;
    cout << "Nhap n: ";
    cin >> n;
    if (n <= 1) {
        cout << "n phai lon hon 1" << endl;
        return 1;
    }
    cout << "Tich cac uoc cua " << n << " la: " << mult_factors(n) << " (lay mod 10e9 + 7)" << endl;
    return 0;
}   