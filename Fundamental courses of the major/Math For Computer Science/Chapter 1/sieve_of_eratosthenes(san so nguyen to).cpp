//san so nguyen to 2->n / a->b
#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

//san so nguyen to tu 2 den n
vector<ll> sieve_of_eratosthenes_1(ll n) {
    vector<ll> primes;
    if (n < 2) return primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

//san so nguyen to tu a den b
vector<ll> sieve_of_eratosthenes_2(ll a, ll b) {
    vector<ll> primes;
    if (a > b || b < 2) return primes;
    if (a < 2) a = 2;
    vector<bool> is_prime(b - a + 1, true);
    for (ll i = 2; i * i <= b; i++) {
        ll start = max(i * i, (a + i - 1) / i * i);
        for (ll j = start; j <= b; j+= i) {
            is_prime[j - a] = false;
        }
    }
    for (ll i = a; i <= b; i++) {
        if(is_prime[i - a]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {

    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: "; 
    cin >> b;

    if (a > b) {
        cout << "Gia tri a phai nho hon hoac bang b." << endl;
        return 0;
    }

    vector<ll> result1 = sieve_of_eratosthenes_1(b);
    cout << "Cac so nguyen to tu 2 den " << b << " la: ";
    for (ll prime : result1) {
        cout << prime << " ";
    }
    cout << endl;

    vector<ll> result2 = sieve_of_eratosthenes_2(a, b);
    cout << "Cac so nguyen to tu " << a << " den " << b << " la: ";
    for (ll prime : result2) {
        cout << prime << " ";
    }
    cout << endl;
    return 0;
}