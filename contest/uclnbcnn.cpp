#include<iostream>

using namespace std;

long long ucln(long long a, long long b) {
    if (a < b) {
        long long t = a;
        a = b;
        b = t;
    }
    while ( b != 0 ) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long bcnn(long long a, long long b) {
    return a * b / ucln(a, b);
}

int main() {

    long long a, b;
    cin >> a >> b;

    cout << ucln(a, b) << " " << bcnn(a, b);
    return 0;
}