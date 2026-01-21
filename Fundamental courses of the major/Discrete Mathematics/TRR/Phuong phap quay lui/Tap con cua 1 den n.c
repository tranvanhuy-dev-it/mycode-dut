#include<stdio.h>

void Out(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void Try(int n, int A[], int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n) Out(n, A);
        else Try(n, A, i + 1);
    }
}

int main() {

    int n, A[100];
    scanf("%d", &n);
    Try(n, A, 1);
    return 0;
}