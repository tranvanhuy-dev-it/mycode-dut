#include<stdio.h>

int out(int n, int A[], int k) {
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) {
            t++;
        }
    }
    if (t == k) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}

void Try(int n, int A[], int k, int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n) out(n, A, k);
        else Try(n, A, k, i+1);
    }
}

int main() {

    int n, k, A[101];
    scanf("%d%d", &n, &k);
    Try(n, A, k, 1);
}