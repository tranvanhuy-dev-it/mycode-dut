#include<stdio.h>

int GCD(int a, int b) {
    if (a == b) return a;
    else if (a > b) return GCD(b, a - b);
    else if (a < b) return GCD(b - a, a);
}

int main() {

    int a, b;
    scanf("%d%d", &a, &b);
    int gcd = GCD(a, b);
    printf("GCD(%d, %d) = %d\n", a, b, gcd);
    return 0;
}