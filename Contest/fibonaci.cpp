#include<iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    if (n == 1 || n == 2) cout << 1;
    else {
        long long a = 1, b = 1;
        long long c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        cout << c;
    }
    return 0;
}