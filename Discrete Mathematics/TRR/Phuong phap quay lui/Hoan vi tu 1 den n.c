#include<stdio.h>

void Out(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Try(int n, int A[], int B[], int i) {
    for (int j = 1; j <= n; j++) {
        if (B[j] == 1) {
            A[i] = j;
            B[j] = 0;
            if (i == n) Out(n, A);
            else Try(n, A, B, i + 1);
            B[j] = 1;
        }
    }
}

int main() {
    int n, A[100], B[100];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        B[i] = 1;
    }
    Try(n, A, B, 1);
    return 0;
}