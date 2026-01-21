#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPerfectSquare(long long x) {
    long long root = (long long)round(sqrt((double)x));
    return root * root == x;
}

int main() {
    int n;
    cin >> n;
    vector<long long> A(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long product = A[i] * A[j];
            if (isPerfectSquare(product)) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
