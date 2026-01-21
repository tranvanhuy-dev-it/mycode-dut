#include<stdio.h>

int Fibo(int n) {
    if (n == 1 || n == 2) return 1;
    return Fibo(n - 1) + Fibo(n - 2);
}

int main() {

    int n;
    scanf("%d", &n);
    int result = Fibo(n);
    printf("Fibnacci(%d) = %d\n", n, result);
    return 0;
}