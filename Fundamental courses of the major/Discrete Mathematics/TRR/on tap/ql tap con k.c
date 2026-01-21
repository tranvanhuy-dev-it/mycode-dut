#include<stdio.h>

int A[100];
int n, k;

void out() {
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) {
            p++;
        }
    }
    if (p == k) {
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

void Try(int i) {
    for (int j = 1; j >= 0; j--) {
        A[i] = j;
        if (i == n) out();
        else Try(i+1);
    } 
}

int main() {

    scanf("%d%d", &n, &k);
    Try(1);
    return 0;
}