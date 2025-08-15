#include <stdio.h>

void init(int n, int a[]) {
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
}

void out(int n, int a[]) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int islast(int n, int a[]) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void gen(int n, int a[]) {
    int i = n - 1;
    while (i > 0 && a[i] >= a[i + 1]) {
        i--;
    }
    if (i > 0) {
        int j = n;
        while (a[j] <= a[i]) {
            j--;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    int l = i + 1, r = n;
    while (l < r) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}

void Method(int a[], int n) {
    init(n, a);
    out(n, a);
    while (!islast(n, a)) {
        gen(n, a);
        out(n, a);
    }
}

int main() {
    int n, a[101];
    scanf("%d", &n);
    Method(a, n);
    return 0;
}
