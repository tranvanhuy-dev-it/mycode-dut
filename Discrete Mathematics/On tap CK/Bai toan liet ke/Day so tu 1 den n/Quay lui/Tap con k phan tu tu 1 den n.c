#include<stdio.h>

void Out(int n, int A[], int k) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) count++;
    } 

    if (count == k) {
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

void Try(int n, int A[], int i, int k) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n) Out(n, A, k);
        else Try(n, A,i + 1, k);
    }
}

int main() {

    int n, A[100], k;
    scanf("%d%d", &n, &k);
    Try(n, A, 1, k);
    return 0;
}