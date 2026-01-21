#include <iostream>
using namespace std;

char C[] = {'a', 'b', 'c', 'd', 'e'};
int k;
int A[10];

void printRes() {
    for (int i = 1; i <= k; i++) {
        cout << C[A[i] - 1] << " ";
    }
    cout << endl;
}

void Try(int i, int start, int n) {
    for (int j = start; j <= n - k + i; j++) {
        A[i] = j;
        if (i == k) {
            printRes();
        } else {
            Try(i + 1, j + 1, n);
        }
    }
}

int main() {
    int n = 5;
    cin >> k;
    Try(1, 1, n);
    return 0;
}
