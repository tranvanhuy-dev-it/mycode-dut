#include<iostream>

using namespace std;

int main() {

    int n, m, A[100][100];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    int B[100] = {};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i] += A[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << B[i] << " " ;
    }
    cout << "\n";
    return 0;
}