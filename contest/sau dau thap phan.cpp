#include<iostream>
using namespace std;

int main() {
    long long a, b;
    int k;
    cin >> a >> b >> k;

    long long r = a % b;
    int digit = 0;

    for (int i = 0; i < k; i++) {
        r *= 10;
        digit = r / b;
        r %= b;
    }

    cout << digit << "\n";
    return 0;
}
