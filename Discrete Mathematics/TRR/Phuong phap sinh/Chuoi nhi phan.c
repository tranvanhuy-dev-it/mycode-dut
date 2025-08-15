#include<stdio.h>

void Out(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Init(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        A[i] = 0;
    }
}

int isLast(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) return 1;
    }
    return 0;
}

void Gen(int n, int A[]) {
    int i = n -1;
    while (A[i] != 0) {
        A[i] = 0;
        i--;
    }
    A[i] = 1;
}

void Method(int n, int A[]) {
    Init(n, A);
    Out(n, A);
    int stop = isLast(n, A);
    while(stop) {
        Gen(n, A);
        Out(n, A);
        stop = isLast(n, A);
    }
}

int main() {

    int n, A[100];
    scanf("%d", &n);
    Method(n, A);
    return 0;
}