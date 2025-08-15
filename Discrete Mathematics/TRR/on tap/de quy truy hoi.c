#include<stdio.h>

int Try(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return 5*Try(n - 1) - 6*Try(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", Try(n));
}