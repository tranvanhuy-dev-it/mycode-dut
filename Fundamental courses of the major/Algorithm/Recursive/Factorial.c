#include<stdio.h>

long long Fac(int n) {
    if (n == 0 || n == 1) return 1;
    return Fac(n - 1)*n;
}

int main() {

    int n;
    scanf("%d", &n);
    long long result = Fac(n);
    printf("%d! = %lld\n", n, result);
    return 0;
}