#include <stdio.h>

float det(float A[4][4]) {
    float det = 0;
    int i, j, k;
    float mtc[3][3];
    for (i = 0; i < 4; i++) {
        int mtci = 0;
        for (j = 1; j < 4; j++) {
            int mtcj = 0;
            for (k = 0; k < 4; k++) {
                if (k == i) continue;
                mtc[mtci][mtcj] = A[j][k];
                mtcj++;
            }
            mtci++;
        }
        float mtcDet = mtc[0][0] * (mtc[1][1] * mtc[2][2] - mtc[1][2] * mtc[2][1])
                     - mtc[0][1] * (mtc[1][0] * mtc[2][2] - mtc[1][2] * mtc[2][0])
                     + mtc[0][2] * (mtc[1][0] * mtc[2][1] - mtc[1][1] * mtc[2][0]);

        det += (i % 2 == 0 ? 1 : -1) * A[0][i] * mtcDet;
    }
    return det;
}
void thecot(float A[4][4], float B[4], int cot, float newMatrix[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            newMatrix[i][j] = (j == cot) ? B[i] : A[i][j];
        }
    }
}
void cramer(float A[4][4], float B[4]) {
    float detA = det(A);
    if (detA == 0) {
        printf("He phuong trinh khong co duy nhat mot nghiem.\n");
        return;
    }
    float Ai[4][4];
    float x[4];
    for (int i = 0; i < 4; i++) {
        thecot(A, B, i, Ai);
        x[i] = det(Ai) / detA;
    }
    printf("He phuong trinh co nghiem: {x, y, z, t} = {");
    for (int i = 0; i < 4; i++) {
        printf("%.2f", x[i]);
        if (i < 3) printf(", ");
    }
    printf("}\n");
}

int main() {
    float A[4][4] = {
        {2, 1 ,-1, 1},
        {1, -1, 2, -1},
        {3, 2, 1, 1},
        {1, 3, -1, 2}
    };
    float B[4] = {8, 5, 15, 10};
    cramer(A, B);

    return 0;
}
