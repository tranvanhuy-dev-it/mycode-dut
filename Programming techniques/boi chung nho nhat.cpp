#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    if (x < y) {
        int z = x;
        x = y;
        y = z;
    }

    if (x % y == 0) {
        printf("%d\n", x);
    } 
    else {
        int a = x;
        int b = y;
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        if (a == 1) {
            printf("%d\n", x * y);
        } else {
            printf("%d\n", (x * y) / a);
        }
    }

    return 0;
}
