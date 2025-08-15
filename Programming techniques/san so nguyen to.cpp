#include <stdio.h>

void nt(int i) {
    for (int j = 1; j * j <= i; j++) {
        if (i % j == 0) {
            printf("%d ", j);
            }
        }
    }

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++) {
        nt(i);
    }

    return 0;
}
