#include<stdio.h>

void init(int n, int A[]) {
    for (int i = 0; i <n; i++) {
        A[i] = 0;
    }
}

void out(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int islast(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void gen(int n, int A[]) {
    int i = n - 1;
    while (A[i] == 1) {
            A[i] = 0;
            i--;
    }
    A[i] = 1;
}

void methor(int n, int A[]) {
    init(n, A);
    out(n, A);
    int stop = islast(n, A);
    while (stop == 0) {
        gen(n, A);
        out(n, A);
        stop = islast(n, A);
    }
}

int main() {

    int n, A[1001];
    scanf("%d", &n);
    methor(n, A);
    return 0;
}