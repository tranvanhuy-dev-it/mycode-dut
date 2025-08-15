#include<stdio.h>

void Out(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    } 
    printf("\n");
}

void Try(int n, int A[], int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n - 1) Out(n, A);
        else Try(n, A,i + 1);
    }
}

int main() {

    int n, A[100];
    scanf("%d", &n);
    Try(n, A, 0);
    return 0;
}