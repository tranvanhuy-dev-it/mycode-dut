#include<stdio.h>

void Out(int n, int A[], char B[]) {
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            printf("%c ", B[i]);
        }
    }
    printf("\n");
}

void Try(int n, int A[], char B[], int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n - 1) Out(n, A, B);
        else Try(n, A, B, i + 1);
    }
}

int main() {

    int n, A[100];
    char B[100] = {'a', 'b', 'c', 'd', 'e'};
    n = 5;
    Try(n, A, B, 1);
    return 0;
}