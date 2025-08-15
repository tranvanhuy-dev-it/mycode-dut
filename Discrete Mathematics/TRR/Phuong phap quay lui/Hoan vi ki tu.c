#include<stdio.h>

void Out(int n, int A[], char C[]) {
    for (int i = 1; i <= n; i++) {
        printf("%c ", C[A[i] - 1]);  
    }
    printf("\n");
}

void Try(int n, int A[], int B[], char C[], int i) {
    for (int j = 1; j <= n; j++) {
        if (B[j] == 1) {
            A[i] = j;
            B[j] = 0;
            if (i == n) Out(n, A, C);
            else Try(n, A, B, C, i + 1);
            B[j] = 1;
        }
    }
}

int main() {
    int n = 5, A[100], B[100];
    char C[5] = {'a', 'b', 'c', 'd', 'e'}; 

    for (int i = 1; i <= n; i++) {
        B[i] = 1;
    }

    Try(n, A, B, C, 1); 
    return 0;
}
