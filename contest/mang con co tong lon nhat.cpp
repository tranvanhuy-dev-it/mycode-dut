#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long A[100001];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    long long max_current = A[1];
    long long max_global = A[1];

    for (int i = 2; i <= n; i++) {
        max_current = max(A[i], max_current + A[i]);
        max_global = max(max_global, max_current);
    }

    cout << max_global << "\n";
    return 0;
}
