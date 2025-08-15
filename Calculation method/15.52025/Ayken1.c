#include<stdio.h>

double Ayken(int n, double A[][6], double x[], double y[], double D[], double c) {
    double W = 1, result = 0, d;
    for (int i = 0; i <= n; i++) {
        A[i][i] = c - x[i];
        W *= (c - x[i]);
        d = c - x[i];
        for (int j = 0; j <= n; j++) {
            if (i != j) {
                A[i][j] = x[i] - x[j];
                d *= (x[i] - x[j]);
            }
            D[i] = d;
        }
        result += y[i] / d;
    } 
    return W * result;
}

int main() {

    double x[] = {1, 3, 5, 7, 9, 11};
    double y[] = {2, 6, 15, 26, 47, 78};
    int n = 5;
    double A[6][6], D[6];

    double c;
    printf("Nhap vao gia tri muon tim: ");
    scanf("%lf", &c);  
    
    printf("f(%0.1lf) = %0.3lf\n\n", c, Ayken(n, A, x, y, D, c));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%-8.2lf ", A[i][j]);
        }
        printf("%-5.1lf ", D[i]);
        printf("\n");
    }

    return 0;
}