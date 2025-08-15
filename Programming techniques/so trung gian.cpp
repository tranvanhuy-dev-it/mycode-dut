#include <stdio.h>

void max1(int a, int b, int c, int *max) {
    *max = a;
    if (b > *max) {
        *max = b;
    }
    if (c > *max) {
        *max = c;
    }
}

void min1(int a, int b, int c, int *min) {
    *min = a;
    if (b < *min) {
        *min = b;
    }
    if (c < *min) {
        *min = c;
    }
}

void trunggian(int a, int b, int c, int max, int min) {
    int tg = a + b + c - max - min;
    printf("Trung gian value: %d\n", tg);
}

int main() {
    int a, b, c, max, min;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    max1(a, b, c, &max);
    min1(a, b, c, &min);
    trunggian(a, b, c, max, min);

    return 0;
}
