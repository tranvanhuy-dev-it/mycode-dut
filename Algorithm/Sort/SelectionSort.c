#include<stdio.h>

void SelectionSort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[index]) {
                index = j;
            }
        }
        if (index != i) {
            int temp = A[i];
            A[i] = A[index];
            A[index] = temp;
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

    int A[20] = {0, 4, 5, 32, 65, 34, 65, 434, 43, 65, 234, 12, 54, 54, 34, 23, 90, 1, 99, 100};

    SelectionSort(A, 20);
    Out(A, 20);
    return 0;
}