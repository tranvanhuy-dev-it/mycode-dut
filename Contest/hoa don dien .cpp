#include<iostream>

using namespace std;

int main() {

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int T;
    if (n >= 151) {
        T = (n - 150 ) * d + 50 * a + 50 * b + 50 * c;
    }
    else if (n >= 101 && n <= 150) {
        T = (n - 100) * c + 50 * a + 50 * b;
    }
    else if (n >= 51 && n < 100) {
        T = (n - 50) * b + 50 * a; 
    }
    else {
        T = n * 50;
    }
    cout << T << "\n";
    return 0;
}