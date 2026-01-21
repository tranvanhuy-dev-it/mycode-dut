#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

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
    show_factors(n);
    show_all_divisor(n);
    return 0;
}