#include<stdio.h>

void Out(int n, int A[], char B[]) {
    for (int i = 0; i < n; i++) {
        printf("%c ", B[A[i]]);
    }
    printf("\n");
}

void Init(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }
}

int isLast(int n, int A[]) {
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) return 1;
    }
    return 0;
}

void Gen(int n, int A[]) {
    int i = n - 2;
    while (i >= 0 && A[i] >= A[i + 1]) i--;
    if (i < 0) return;

    int j = n - 1;
    while (A[i] >= A[j]) j--;

    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;

    int l = i + 1, r = n - 1;
    while (l < r) {
        temp = A[l];
        A[l] = A[r];
        A[r] = temp;
        l++;
        r--;
    }
}

void Method(int n, int A[], char B[]) {
    Init(n, A);
    Out(n, A, B);
    while (isLast(n, A)) {
        Gen(n, A);
        Out(n, A, B);
    }
}

int main() {
    int n = 5, A[100];
    char B[5] = {'a', 'b', 'c', 'd', 'e'};
    Method(n, A, B);
    return 0;
}
