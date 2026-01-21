#include <stdio.h>

int n, k, A[101], p = 0;

void out() {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += A[i];
    if (sum == k) { 
        p++; 
        printf("Nghiem thu %-3d:", p);
        for (int i = 1; i <= n; i++) {
            printf(" x%d = %d,  ", i, A[i]);
        }
        printf("\n");
    }
}

void init() {
    for (int i = 1; i <= n; i++) A[i] = 0;
    A[1] = k; 
}

int islast() {
    for (int i = 1; i < n; i++) {
        if (A[i] != 0) return 0;
    }
    return A[n] == k;
}

void gen() {
    int i = n;
    while (i > 1 && A[i] == 0) i--;
    
    if (i >= 1) {
        A[i]--; 
        int sum = A[i];
        for (int j = 1; j < i; j++) sum += A[j];
        A[i+1] = k - sum; 
        for (int j = i+2; j <= n; j++) A[j] = 0;
    }
}

void method() {
    init();
    out();
    while (!islast()) {
        gen();
        out();
    }
}

int main() {
    scanf("%d%d", &n, &k);
    
    method();
    printf("\nTong so nghiem hop le: %d\n", p);
    return 0;
}