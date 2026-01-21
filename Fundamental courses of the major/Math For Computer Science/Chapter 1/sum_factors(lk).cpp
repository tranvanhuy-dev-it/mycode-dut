#include <iostream>
#include <map>
#include <cmath>

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

//tong cac uoc
long long sum_factors(long long n) {
    map<long long, long long> res = prime_factors(n);
    long long sum = 1;
    for (auto x : res) {
        sum *= ((pow(x.first, x.second + 1) - 1) / (x.first - 1));
    }
    return sum;
}

int main() {
    long long n;
    cout << "Nhap n: ";
    cin >> n;
    if (n <= 1) {
        cout << "n phai lon hon 1" << endl;
        return 1;
    }
    cout << "Tong cac uoc cua " << n << " la: " << sum_factors(n) << endl;
    return 0;
}   