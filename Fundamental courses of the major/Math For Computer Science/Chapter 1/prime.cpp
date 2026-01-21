#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

//tinh modulo
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

//kiem tra so nguyen to
bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
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

//in ra thua so nguyen to
void show_factors(long long n) {
    map res = prime_factors(n);
    bool first = true;
    cout << n << " = ";
    for (auto x : res) {
        if (!first) {
            cout << " x ";
        }
        cout << x.first << "^" << x.second;
        first = false;
    }
    cout << endl;
}

//tong cac uoc
long long sum_factors(long long n) {
    map<long long, long long> res = prime_factors(n);
    long long sum = 1;
    for (auto x : res) {
        sum *= ((pow(x.first, x.second + 1) - 1) / (x.first - 1));
    }
    return sum;
}

//so uoc
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

//kiem tra so hoan hao
bool is_perfect_number(long long n) {
    return n == sum_factors(n) - n;
}

//in ra tat ca cac uoc
void show_all_divisor(int n) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    cout << "Cac uoc cua " << n << " la: ";
    for (auto d : divisors) {
        cout << d << " ";
    }
    cout << endl;
}

int main() {
    long long n;
    cout << "Nhap n: ";
    cin >> n;
    if (n <= 1) {
        cout << "n phai lon hon 1" << endl;
        return 1;
    }
    if (is_prime(n)) {
        cout << n << " la so nguyen to" << endl;
    } else {
        cout << n << " khong phai la so nguyen to" << endl;
    }
    if (is_perfect_number(n)) {
        cout << n << " la so hoan hao" << endl;
    } else {
        cout << n << " khong phai la so hoan hao" << endl;
    }
    show_factors(n);
    cout << "So uoc cua " << n << " la: " << number_factors(n) << endl;
    show_all_divisor(n);
    cout << "Tich cac uoc cua " << n << " la: " << mult_factors(n) << " (lay mod 10e9 + 7)" << endl;
    cout << "Tong cac uoc cua " << n << " la: " << sum_factors(n) << endl;

    return 0;
}   