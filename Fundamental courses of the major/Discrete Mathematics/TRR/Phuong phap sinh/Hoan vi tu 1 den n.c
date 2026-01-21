#include<stdio.h>

void init(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }
}

void out(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int islast(int n, int A[]) {
    for (int i = 1; i <= n - 1; i++) {
        if (A[i] < A[i + 1]) return 1;
    }
    return 0;
}

void gen(int n, int A[]) {
    int i = n - 1;
    while (i > 0 && A[i] >= A[i + 1]) i--;
    int j = n;
    while (A[i] > A[j]) j--;
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
    int l = i + 1, r = n;
    while (l < r) {
        int t = A[l];
        A[l] = A[r];
        A[r] = t;
        l++;
        r--;
    }
}

void method(int n, int A[]) {
    init(n, A);
    out(n, A);
    int stop = islast(n, A);
    while (stop) {
        gen(n, A);
        out(n, A);
        stop = islast(n, A);
    }
}

int main() {

    int n, A[101];
    scanf("%d", &n);
    method(n, A);
    return 0;
}