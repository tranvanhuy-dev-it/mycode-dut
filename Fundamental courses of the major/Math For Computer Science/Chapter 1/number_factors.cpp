#include <iostream>
#include <map>

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

//so uoc
long long number_factors(long long n) {
    map<long long, long long> factors = prime_factors(n);
    long long cnt = 1;
    for (auto x : factors) {
        cnt *= (x.second + 1);
    }
    return cnt;
}

int main() {
    long long n;
    cout << "Nhap n: ";
    cin >> n;
    if (n <= 1) {
        cout << "n phai lon hon 1" << endl;
        return 1;
    }
    cout << "So uoc cua " << n << " la: " << number_factors(n) << endl;
    return 0;
}