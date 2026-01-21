#include <stdio.h>

#define N 8

void TaoBangHermite(float z[], float Q[N][N], float x[], float y[], float dy[], float d2y[]) {
    z[0] = z[1] = z[2] = x[0];
    z[3] = z[4] = x[1];
    z[5] = z[6] = z[7] = x[2];

    Q[0][0] = Q[1][0] = Q[2][0] = y[0];
    Q[3][0] = Q[4][0] = y[1];
    Q[5][0] = Q[6][0] = Q[7][0] = y[2];

    Q[1][1] = dy[0];
    Q[2][1] = (Q[2][0] - Q[1][0]) / (z[2] - z[1]);
    Q[3][1] = dy[1];
    Q[4][1] = (Q[4][0] - Q[3][0]) / (z[4] - z[3]);
    Q[6][1] = dy[2];
    Q[7][1] = (Q[7][0] - Q[6][0]) / (z[7] - z[6]);

    Q[2][2] = d2y[0] / 2.0;
    Q[5][2] = (Q[5][1] - Q[4][1]) / (z[5] - z[3]);
    Q[6][2] = d2y[2] / 2.0;

    for (int j = 3; j < N; j++) {
        for (int i = 0; i < N - j; i++) {
            Q[i][j] = (Q[i+1][j-1] - Q[i][j-1]) / (z[i+j] - z[i]);
        }
    }
}

float NoiSuyHermite(float z[], float Q[N][N], float X) {
    float result = Q[0][0], term = 1.0;
    for (int i = 1; i < N; i++) {
        term *= (X - z[i-1]);
        result += Q[0][i] * term;
    }
    return result;
}

int main() {
    float x[3], y[3], dy[3], d2y[3];
    float z[N], Q[N][N], X;

    printf("Nhap x[0] y[0] y'[0] y''[0]: ");
    scanf("%f%f%f%f", &x[0], &y[0], &dy[0], &d2y[0]);

    printf("Nhap x[1] y[1] y'[1]: ");
    scanf("%f%f%f", &x[1], &y[1], &dy[1]);
    d2y[1] = 0;

    printf("Nhap x[2] y[2] y'[2] y''[2]: ");
    scanf("%f%f%f%f", &x[2], &y[2], &dy[2], &d2y[2]);

    printf("Nhap gia tri x can noi suy: ");
    scanf("%f", &X);

    TaoBangHermite(z, Q, x, y, dy, d2y);
    printf("Gia tri noi suy tai x = %.6f la: %.6f\n", X, NoiSuyHermite(z, Q, X));

    return 0;
}
