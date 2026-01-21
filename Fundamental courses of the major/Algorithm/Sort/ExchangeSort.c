#include<stdio.h>

void ExchangeSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
}

void Out(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {

    int A[20] = {0, -4, 5, 32, 65, 34, 65, 434, 43, 65, 234, 12, 54, 54, 34, 23, 90, 1, 99, 100};

    ExchangeSort(A, 20);
    Out(A, 20);
    return 0;
}