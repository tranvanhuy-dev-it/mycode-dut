#include<stdio.h>

void out(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        printf("%d", A[i]);
    }
    printf("\n");
}

void Try(int n, int A[], int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n) out(n, A);
        else Try(n, A, i+1);
    }
}

int main() {

    int n, A[101];
    scanf("%d", &n);
    Try(n, A, 1);
    return 0;
}