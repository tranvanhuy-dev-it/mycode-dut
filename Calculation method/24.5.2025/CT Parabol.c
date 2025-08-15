#include<stdio.h>

float TichPhanPRB(float x[], float y[], int n, float a, float b) {
    float h = (b - a) / n;
    float result = y[0] + y[n];
    for (int i = 1; i <= n - 1; i++) {
        if (i % 2 == 0) result += 2*y[i];
        else result += 4*y[i];
    }
    result *= h/3;
    return result;
}

int main() {

    int n;
    float a, b;
    float x[100], y[100];
    printf("Nhap n: "); scanf("%d", &n);
    printf("Nhap toa do x: ");
    for (int i = 0; i <= n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Nhap toa do y: ");
    for (int i = 0; i <= n; i++) {
        scanf("%f", &y[i]);
    }

    printf("Ket qua: %f\n", TichPhanPRB(x, y, n, x[0], x[n]));
    return 0;
}