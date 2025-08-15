#include<stdio.h>

void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i, temp = A[i];
        while (j > 0 && temp < A[j - 1]) {
            A[j] = A[j - 1];
            j = j - 1;
        }
        A[j] = temp;
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

    InsertionSort(A, 20);
    Out(A, 20);
    return 0;
}