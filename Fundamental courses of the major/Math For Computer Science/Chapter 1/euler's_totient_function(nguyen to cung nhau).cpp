//cho n nhap tu ban phim, co bao nhieu so la nguyen to cung nhau voi n trong doan 1->n, liet ke chung (gcd = 1)
//kiem tra so nguyen to bang 2 cach
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
typedef long long ll;

using namespace std;

//uoc chung lon nhat dung eculid
ll gcd_euclid(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_euclid(b, a % b);
    }
}

//tim cac so nguyen to cung nhau voi n
vector<ll> list_coprimes(ll n) {
    vector<ll> result;
    for (ll i = 1; i <= n; i++) {
        if (gcd_euclid(n, i) == 1) {
            result.push_back(i);
        }
    }
    return result;
} //O(n log n)

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
ll eulers_totient_function(ll n) {
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
}//O(n)

//kiem tra so nguyen to truyen thong
bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

//kiem tra so nguyen to dung euler
bool is_prime_euler(ll n) {
    return eulers_totient_function(n) == n - 1;
}

int main() {

    ll n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Kiem tra so nguyen to cung nhau voi 2 cach:\n";
    cout << "Cach 1:\n";
    vector<ll> coprimes = list_coprimes(n);
    ll count = coprimes.size();
    cout << "Co " << count << " so nguyen to cung nhau voi " << n << " trong doan 1 den " << n << ": ";
    for (ll num : coprimes) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Cach 2:\n";
    ll phi_n = eulers_totient_function(n);
    cout << "Co " << phi_n << " so nguyen to cung nhau voi " << n << " trong doan 1 den " << n << endl;

    cout << "\nKiem tra so nguyen to bang 2 cach:\n";
    cout << "Cach 1:\n";    
    if (is_prime(n)) {
        cout << n << " la so nguyen to" << endl;
    } else {
        cout << n << " khong phai la so nguyen to" << endl;
    }

    cout << "Cach 2:\n";
    if (is_prime_euler(n)) {
        cout << n << " la so nguyen to" << endl;
    } else {
        cout << n << " khong phai la so nguyen to" << endl;
    }
    return 0;
}