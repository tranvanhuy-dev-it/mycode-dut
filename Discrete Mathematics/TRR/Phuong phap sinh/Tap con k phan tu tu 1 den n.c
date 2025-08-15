#include<stdio.h>

void init(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        A[i] = 0;
    }
}

void out(int n, int A[], int k) {
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 1) p++;
    }
    if (p == k) {
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) printf("%d ", i);
        }
        printf("\n");
    }
}

int islast(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) return 1;
    }
    return 0;
}

void gen(int n, int A[]) {
    int i = n;
    while (A[i] == 1 ) {
        A[i] = 0;
        i--;
    }
    A[i] = 1;
} 

void method(int n, int A[], int k) {
    init(n, A);
    out(n, A, k);
    int stop = islast(n, A);
    while (stop) {
        gen(n, A);
        out(n, A, k);
        stop = islast(n, A);
    } 
}

int main() {

    int n, k, A[101];
    scanf("%d%d", &n, &k);
    method(n, A, k);
}