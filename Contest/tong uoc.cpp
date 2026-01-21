#include<iostream>

using namespace std;



int main() {

    unsigned long long n;
    cin >> n;

    unsigned long long sum = 0;
    for (unsigned long long i = 1; i * i<= n; i++) {
        if (n % i == 0) {
            if (i == n/i) sum += i;
            else sum = sum + i + n/i;
        }
    }
    cout << sum;
    return 0;
}