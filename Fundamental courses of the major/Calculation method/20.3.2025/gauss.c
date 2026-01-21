#include <stdio.h>

void gauss(float A[4][5]) {
    int i, j, k;
    float m;
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            m = A[j][i] / A[i][i];
            for (k = i; k <= 4; k++) {
                A[j][k] -= m * A[i][k];
            }
        }
    }
    float x[4];
    for (i = 3; i >= 0; i--) {
        x[i] = A[i][4];
        for (j = i + 1; j < 4; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    printf("He phuong trinh co nghiem: {x, y, z, t} = {");
    for (i = 0; i < 4; i++) {
        printf("%.2f", x[i]);
        if(i == 3) continue;
        printf(", ");
    }
    printf("}\n");
}

int main() {
    float A[4][5] = {
        {2, 1 ,-1, 1, 8},
        {1, -1, 2, -1, 5},
        {3, 2, 1, 1, 15},
        {1, 3, -1, 2, 10}
    };
    gauss(A);
    return 0;
}
