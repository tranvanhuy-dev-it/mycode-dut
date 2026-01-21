#include <stdio.h>

void nhap(int n, int A[100]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
}

void xuat(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", A[i]);
    }
    printf("\n");  // Thêm xuống dòng sau khi in ra
}

void xoaam(int *A, int *n) {
    int i = 0, j = 0;
    while (i < *n) {
        if (A[i] < 0) {
            // Khi gặp phần tử âm, không tăng i mà chỉ giảm n
            *n -= 1;  // Giảm kích thước mảng
            for (j = i; j < *n; j++) {
                A[j] = A[j + 1];  // Dịch chuyển các phần tử
            }
        } else {
            i++;  // Chỉ tăng i nếu không phải phần tử âm
        }
    }
}

int main() {
    int n, A[100];
    scanf("%d", &n);
    nhap(n, A);
    xoaam(A, &n);
    xuat(A, n);  // Truyền n mà không phải &n
    return 0;
}
