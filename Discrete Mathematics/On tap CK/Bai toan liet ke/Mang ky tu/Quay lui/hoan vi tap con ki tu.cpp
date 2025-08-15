#include <iostream>
using namespace std;

char C[] = {'a', 'b', 'c', 'd', 'e'};
int n = 5, k;
int A[10];       // luu to hop
int used[10];    // danh dau da dung
char subset[10]; // luu k ki tu
char res[10];    // luu hoan vi tam thoi

void printPerm() {
    for (int i = 0; i < k; i++) {
        cout << res[i];
    }
    cout << endl;
}

void permute(int i) {
    for (int j = 0; j < k; j++) {
        if (used[j] == 0) {
            res[i] = subset[j];
            used[j] = 1;
            if (i == k - 1) {
                printPerm();
            } else {
                permute(i + 1);
            }
            used[j] = 0;
        }
    }
}

void processSubset() {
    for (int i = 1; i <= k; i++) {
        subset[i - 1] = C[A[i] - 1];
    }
    for (int i = 0; i < k; i++) used[i] = 0;
    permute(0);
}

void Try(int i, int start) {
    for (int j = start; j <= n - k + i; j++) {
        A[i] = j;
        if (i == k) {
            processSubset();
        } else {
            Try(i + 1, j + 1);
        }
    }
}

int main() {
    cout << "Nhap k: ";
    cin >> k;
    Try(1, 1);
    return 0;
}
