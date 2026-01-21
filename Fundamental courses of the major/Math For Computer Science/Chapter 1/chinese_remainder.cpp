#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

/*
    Euclid mở rộng
    Tìm d = gcd(a, b) và x, y sao cho: a*x + b*y = d
*/
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

/*
    Nghịch đảo modulo: Trả về a^{-1} mod m nếu tồn tại
*/
ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll d = extended_gcd(a, m, x, y);
    if (d != 1) return -1;   
    return (x % m + m) % m;
}

/*
    Giải hệ thặng dư Trung Hoa:
        x ≡ a[i] (mod m[i])
    Điều kiện: các m[i] đôi một nguyên tố cùng nhau
    Trả về: (x0, M) với nghiệm tổng quát x = x0 + kM
*/
pair<ll, ll> chinese_remainder(const vector<ll>& a, const vector<ll>& m) {
    ll M = 1;
    for (ll mi : m) M *= mi;

    ll x0 = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        ll Mi = M / m[i];
        ll yi = mod_inverse(Mi, m[i]);
        if (yi == -1) {
            cout << "Khong ton tai nghiem (cac m khong nguyen to cung nhau)\n";
            return {0, 0};
        }
        x0 = (x0 + a[i] * Mi % M * yi % M) % M;
    }

    return {x0, M};
}

int main() {
    int n;
    cout << "Nhap so phuong trinh: ";
    cin >> n;

    vector<ll> a(n), m(n);

    cout << "\nNhap cac gia tri a:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];
    }

    cout << "\nNhap cac gia tri m:\n";
    for (int i = 0; i < n; i++) {
        cout << "m[" << i + 1 << "] = ";
        cin >> m[i];
    }

    auto res = chinese_remainder(a, m);

    if (res.second != 0) {
        cout << "\nNghiem cua he:\n";
        cout << "x = " << res.first 
             << " + k * " << res.second 
             << "\n";
    }

    return 0;
}
