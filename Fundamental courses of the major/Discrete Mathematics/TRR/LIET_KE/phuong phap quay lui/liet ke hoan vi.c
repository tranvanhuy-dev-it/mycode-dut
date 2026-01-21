#include<stdio.h>

void out(int n, int a[]) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Try(int i, int a[], int b[], int n) {
    for (int j = 1; j <= n; j++) {
        if (b[j] == 1) {
            a[i] = j;
            b[j] = 0;
            if (i == n) out(n, a);
            else Try (i+1, a, b, n);
            b[j] = 1;
        }
    }
}

int main() {

    int n, a[101], b[101];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        b[i] = 1;
    }
    Try(1, a, b, n);

    return 0;
}