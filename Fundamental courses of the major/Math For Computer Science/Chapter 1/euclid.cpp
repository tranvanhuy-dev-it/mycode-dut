//uoc chung lon nhat, boi chung nho nhat bang 2 cach
#include <iostream>
using namespace std;
typedef long long ll;

//uoc chung lon nhat eculid
ll gcd_euclid(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_euclid(b, a % b);
    }
}

//boi chung nho nhat
ll lcm(ll a, ll b) {
    return (a * b) / gcd_euclid(a, b);
}

//uoc chung lon nhat dung vong lap
ll gcd_loop(ll a, ll b) {
    while (b!= 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {

    ll a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "nhap b: ";
    cin >> b;

    ll ucln = gcd_euclid(a, b);
    ll ucln2 = gcd_loop(a, b);
    ll bcnn = lcm(a, b);

    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << ucln << endl;
    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << ucln << endl;
    cout << "Boi chung nho nhat cua " << a << " va " << b << " la: " << bcnn << endl;
}