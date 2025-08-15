#include <stdio.h>
#include<math.h>

void SaiPhan(float x[], float y[], float A[][5], int n) {
    for (int i = 0; i < n; i++) {
        A[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = j; i <  n; i++) {
            A[i][j] = A[i][j-1] - A[i-1][j-1];
        }
    }

    printf("Bang sai phan: \n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%5.2f  ", A[i][j]);
        }
        printf("\n");
    }
}

int giaithua(int key) {
    if (key == 0 || key == 1 ) return 1;
    return key*giaithua(key-1);
}

float NoiSuyNewton(float x[], float y[], float A[][5], float h, int n, float key) {
    float result = A[0][0];

    for (int i = 1; i < n; i++) {
        float temp = 1.0;
        for (int j = 0; j < i; j++) {
            temp *= (key - x[j]);
        }
        temp *= A[i][i] / ((pow(h, n) * giaithua(i)));
        result += temp;
    }
    return result;
}

int main() {
    float x[5] = {1, 2, 3, 4, 5};
    float y[5] = {2, 4, 5, 9, 8};
    float A[5][5];
    float h = x[1] - x[0];
    SaiPhan(x, y, A, 5);
    float kq = NoiSuyNewton(x, y, A, h, 5, 2.5);
    printf("\nf(2.5) = %f\n", kq);
    return 0;
}
