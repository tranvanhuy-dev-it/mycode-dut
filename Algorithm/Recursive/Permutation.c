#include<stdio.h>

void Out(int A[], int n) {
    for (int i = 0; i < n; i++) {
            printf("%d ", A[i]);
    }
    printf("\n");
}

void Try(int A[], int B[], int n, int i) {
    for (int j = 1; j <= n; j++) {
        if (B[j] == 1) {
            A[i] = j;
            B[j] = 0;
            if (i == n -1) Out(A, n);
            else Try(A, B, n, i + 1);
            B[j] = 1;
        }
    }
}
int main() {

    int A[100], B[100], n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) B[i] = 1;
    Try(A, B, n, 0);
    return 0;
}