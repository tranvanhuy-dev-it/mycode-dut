#include<stdio.h>

void out(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Try(int n, int i, int A[], int B[], int C[], int X[]) {
    for (int j = 1; j <= n; j++) {
        if (A[j] == 1 && B[i+j] == 1 && C[i - j + n] == 1) {
            X[i] = j;
            A[j] = 0;
            B[i + j] = 0;
            C[i - j + n] = 0;
            if (i == n) out(n, X);
            else Try(n, i+1, A, B, C, X);
            A[j] = 1;
            B[i + j] = 1;
            C[i - j + n] = 1;
        }
    }
}

int main() {

    int n,  A[101], B[201], C[201], X[101];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        A[i] = 1;
    }
    for (int i = 1; i <= 2*n; i++) {
        B[i] = 1;
        C[i] = 1;
    }
    Try(n, 1, A, B, C, X);
    return 0;
}