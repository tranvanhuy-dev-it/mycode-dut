#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int f[10000] = {0};

    f[0] = 1;
    f[1] = 1;
    f[2] = 2;

    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }

    printf("So cach leo %d bac: %d\n", n, f[n]);
    return 0;
}