#include<stdio.h>

void Out(int n, int A[], char C[], int k) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) count++;
    } 

    if (count == k) {
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) {
                printf("%c ", C[i - 1]);
            }
        }
        printf("\n");
    }
}

void Try(int n, int A[], char C[], int i, int k) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n) Out(n, A, C, k);
        else Try(n, A, C, i + 1, k);
    }
}

int main() {

    int n = 5, A[100], k;
    char C[100] = {'a', 'b', 'c', 'd', 'e'};
    scanf("%d", &k);
    Try(n, A, C, 1, k);
    return 0;
}