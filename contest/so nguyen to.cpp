#include<iostream>

using namespace std;

bool snt(long long n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    long long n;
    cin >> n;
    if (snt(n)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}