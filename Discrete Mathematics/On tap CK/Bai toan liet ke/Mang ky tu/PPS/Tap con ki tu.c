#include<stdio.h>

void init(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        A[i] = 0;
    }
}

void out(int n, int A[], char B[]) {
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) {
            printf("%c", B[i - 1]);
        }
    }
    printf("\n");
}

int islast(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) {
            return 1;
        }
    }
    return 0;
}

void gen(int n, int A[]) {
    int i = n;
    while (A[i] == 1) {
        A[i] = 0;
        i--;
    }
    A[i] = 1;
}

void method(int n, int A[], char B[]) {
    init(n, A);
    out(n, A, B);
    int stop = islast(n, A);
    while (stop) {
        gen(n, A);
        out(n, A, B);
        stop = islast(n, A);
    }
}

int main() {

    int n, A[101];
    n = 5;
    char B[100] = {'a', 'b', 'c', 'd', 'e'};
    method(n, A, B);
    return 0;
}