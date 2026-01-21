#include<stdio.h>

void Out(int A[], char S[], int n) {
    for(int i = 0; i < n; i++) {
        if (A[i] == 1) {
            printf("%c ", S[i]);
        }
    }
    printf("\n");
}

void Try(int A[], char S[], int n, int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n - 1) Out(A, S, n);
        else Try(A, S, n, i + 1);
    }
}

int main() {
    
    char S[100] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int n = 6, A[100];
    Try(A, S, n, 0);
    return 0;
}