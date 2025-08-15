#include<stdio.h>

int partition(int A[], int l, int r) {
    int p = A[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (A[j] < p) {
            i++;
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    int t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;
    return i+1;
}

void QuickSort(int A[], int l, int r) {
    if (l < r) {
        int p = partition(A, l, r);
        QuickSort(A, l, p - 1);
        QuickSort(A, p + 1, r);
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

    QuickSort(A, 0, 19);
    Out(A, 20);
    return 0;
}