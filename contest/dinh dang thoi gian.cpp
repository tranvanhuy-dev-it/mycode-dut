#include<iostream>

using namespace std;

int main() {

    unsigned long long n;
    cin >> n;
    unsigned long long h, m, s;

    if (n < 60) {
        h = 0;
        m = 0;
        s = n;
    }
    else if (n >= 60 && n < 3600) {
        m = n / 60;
        s = n % 60;
    }
    else if (n >= 3600) {
        h = n / 3600;
        m = (n - h * 3600) / 60;
        s = n - m * 60 - h * 3600;
    }

    cout << h << " " << m << " " << s << "\n";

    return 0;
}