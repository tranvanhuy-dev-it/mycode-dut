#include <stdio.h>

int a(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a0 = 0, a1 = 1, an;
    for (int i = 2; i <= n; i++) {
        an = 5 * a1 - 6 * a0;
        a0 = a1;
        a1 = an;
    }
    return a1;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", a(n));
}