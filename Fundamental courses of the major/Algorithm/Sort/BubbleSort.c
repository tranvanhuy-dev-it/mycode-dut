#include<stdio.h>

void BubbleSort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (A[j] < A[j-1]) {
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
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

    int A[20] = {0, 4, 5, -32, 65, 34, 65, 434, 43, -65, 234, 12, 54, 54, 34, 23, 90, 1, 99, -100};

    BubbleSort(A, 20);
    Out(A, 20);
    return 0;
}