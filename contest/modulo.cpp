#include <iostream>
using namespace std;

long long power_mod(long long a, long long b, long long c) {
    long long result = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % c;
        a = (a * a) % c;
        b /= 2;
    }
    return result;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << power_mod(a, b, c) << "\n";
    return 0;
}
