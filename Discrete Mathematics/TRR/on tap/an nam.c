#include<stdio.h>
#define ll long long

ll A[4][4];
ll d = 0;

void input() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%lld", &A[i][j]);
        }
    }
}

void Try(int i, int j) {
    if (i == 3 && j == 3) return;

    if (j < 3 && A[i][j + 1] > A[i + 1][j]) {
        j = j + 1;
        d += A[i][j]; 
        Try(i, j);
    } else if (i < 3) {
        i = i + 1;
        d += A[i][j];
        Try(i, j); 
    }
}

int main() {
    input();
    d = A[0][0]; 
    Try(0, 0);
    printf("%lld\n", d);
    return 0;
}
