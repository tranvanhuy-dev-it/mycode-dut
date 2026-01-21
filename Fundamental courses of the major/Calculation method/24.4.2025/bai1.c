#include <stdio.h>

void Mult_Matrix(double A[3][3], double B[3][3], double C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void Danilevsky(double A[3][3]) {
    double M[3][3], M1[3][3], temp[3][3];
    
    for (int k = 2; k >= 1; k--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                M[i][j] = (i == j) ? 1.0 : 0.0;
                M1[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
        if (A[k][k-1] == 0) continue; 
        for (int j = 0; j < 3; j++) {
            M[k-1][j] = -A[k][j] / A[k][k-1];
            M1[j][k-1] = A[k][j];
        }
        M[k-1][k-1] = 1.0 / A[k][k-1];
        Mult_Matrix(A, M, temp);
        Mult_Matrix(M1, temp, A);
    }
}

void Out(double A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5.1f ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double A[3][3] = {
        {2, 1, 0},
        {1, 3, 1},
        {0, 1, 2}};
    
    Out(A);
    Danilevsky(A);
    printf("\n");
    Out(A);
    
    return 0;
}