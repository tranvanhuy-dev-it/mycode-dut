#include<stdio.h>

void Out(int A[], int n) {
    for(int i = 1; i <= n; i++) {
        if (A[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void Try(int A[], int n, int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n) Out(A, n);
        else Try(A, n, i + 1);
    }
}

int main() {
    
    int n = 6, A[100];
    scanf("%d", &n);
    Try(A, n, 1);
    return 0;
}