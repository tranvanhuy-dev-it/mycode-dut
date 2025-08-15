#include<stdio.h>

int n, k, X[100], A[100], B[100];

void Out(int k) {
    for (int i = 1; i <= k; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
}

void Permute(int k, int i) {
    for (int j = 1; j <= k; j++) {
        if (A[j] == 1) {
            B[i] = X[j];
            A[j] = 0;
            if (i == k) Out(k);
            else Permute(k, i + 1);
            A[j] = 1;
        }
    }
}

void Try(int i, int start) {
    for (int j = start; j <= n; j++) {
        X[i] = j;
        if (i == k) {
            for (int t = 1; t <= k; t++) A[t] = 1;
            Permute(k, 1);
        } else {
            Try(i + 1, j + 1);
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    Try(1, 1);
    return 0;
}
