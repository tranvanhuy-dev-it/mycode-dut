#include <stdio.h>
#include <math.h>

void gauss(float A[2][3], float key) {
    float m;
    m = A[1][0] / A[0][0];
    for (int k = 0; k < 3; k++) {
        A[1][k] -= m * A[0][k];
    }

    float x[2];
    x[1] = A[1][2] / A[1][1];
    x[0] = (A[0][2] - A[0][1] * x[1]) / A[0][0];

    printf("y = %.2f + %.2fx\n", x[0], x[1]);
    printf("f(2.5) = %f\n", x[0] + 2.5*x[1]);
}

int main() {
    float x[] = {1, 2, 3, 4, 5};
    float y[] = {2, 4, 5, 9, 8};
    int n = 5;
    float sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;

    for (int i = 0; i < n; i++) {
        sumx += x[i];
        sumy += y[i];
        sumx2 += x[i] * x[i];
        sumxy += x[i] * y[i];
    }

    float A[2][3];
    A[0][0] = n;
    A[0][1] = sumx;
    A[0][2] = sumy;
    A[1][0] = sumx;
    A[1][1] = sumx2;
    A[1][2] = sumxy;

    float key = 2.5;

    gauss(A, key);

    return 0;
}
