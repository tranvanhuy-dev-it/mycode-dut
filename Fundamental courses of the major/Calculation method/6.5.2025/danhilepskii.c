#include <stdio.h>
#include <math.h>

double a[4], X[50], M[3][3], N[3][3], kq[3][3], A[4];
int n, p;

void input() {
    p = 0;
    n = 3;
    for (int i = 0; i <= n; i++) {
        a[i] = A[i];
    }
}

double f(double a[], double x) {
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += a[i] * pow(x, n - i);
    }
    return sum;
}

void chia_doi(double temp1, double x2) {
    double temp2 = temp1 + 0.1;
    while (temp1 <= x2) {
        if (f(a, temp1) * f(a, temp2) < 0) {
            double l = temp1, r = temp2, m = (l + r) / 2;

            if (f(a, l) > 0) {
                double tmp = l;
                l = r;
                r = tmp;
            }

            while (fabs(r - l) > 1e-4) {
                m = (l + r) / 2;
                if (f(a, m) < 0) l = m;
                else r = m;
            }

            X[p++] = m;
        }

        temp1 = temp2;
        temp2 += 0.1;
    }
}

void xuly() {
    double m1 = 0, m2 = 0, x1, x2;

    for (int i = 1; i <= n; i++) {
        if (fabs(a[i]) > m1) m1 = fabs(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (fabs(a[i]) > m2) m2 = fabs(a[i]);
    }

    x1 = fabs(a[n]) / (m2 + fabs(a[n]));
    x2 = 1.0 + (m1 / fabs(a[0]));

    chia_doi(-x2, -x1);
    chia_doi(x1, x2);
}

void output() {
    printf("Ma tran da cho co %d gia tri rieng:\n", p);
    for (int i = 0; i < p; i++) {
        printf("x%d = %.4lf\n", i + 1, X[i]);
    }
    printf("\n\n");
}

void mult_matrix(double A[3][3], double B[3][3]) {
    double temp[3][3] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            kq[i][j] = temp[i][j];
        }
    }
}

void Frobenius_matrix(int line) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            M[i][j] = (i == j) ? 1 : 0;
            N[i][j] = (i == j) ? 1 : 0;
        }
    }

    double temp = kq[line][line - 1];

    for (int j = 0; j < 3; j++) {
        M[line - 1][j] = kq[line][j];
    }

    for (int j = 0; j < 3; j++) {
        if (line - 1 != j)
            N[line - 1][j] = -kq[line][j] / temp;
        else
            N[line - 1][j] /= temp;
    }

    mult_matrix(M, kq);
    mult_matrix(kq, N);
}

void Da_nhi_lep_ski(double heso[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            kq[i][j] = heso[i][j];
        }
    }

    for (int line = 2; line >= 1; line--) {
        Frobenius_matrix(line);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.4lf   ", kq[i][j]);
        }
        printf("\n");
    }

    A[0] = 1;
    for (int i = 0; i < 3; i++) {
        A[i + 1] = -kq[0][i];
    }

    printf("\n");
    input();
    xuly();
    output();
}

int main() {
    double A[3][3] = {{4, 1, -1}, {1, 3, -1}, {-1, -1, 2}};
    double B[3][3] = {{1, 3, 2}, {4, -5, -6}, {9, 7, -8}};

    Da_nhi_lep_ski(A);
    Da_nhi_lep_ski(B);
}
