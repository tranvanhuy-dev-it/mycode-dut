#include<stdio.h>

float TichPhanNC(float x[], float y[], int n, float a, float b) {
    float h = (b - a) / n;
    float result = y[0] / 2 + y[n] / 2;
    for (int i = 1; i <= n - 1; i++) {
        result += y[i];
    }
    result *= h;
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

    printf("Ket qua: %f\n", TichPhanNC(x, y, n, x[0], x[n]));
    return 0;
}