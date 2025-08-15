#include <stdio.h>
#include <math.h>

#define E 0.0001
#define n 5

double A[5][6] = {
    {12, 1, 2, -1, 3, 20},
    {1, 15, -3, 2, 1, 25},
    {2, -3, 18, 1, -2, 30},
    {-1, 2, 1, 20, 1, 28},
    {3, 1, -2, 1, 25, 35}
};

double x[5] = {1.66, 2.08, 2.5, 2.33, 2.92};
double y[5];

void xuly() {
    double t;
    do {
        t = 0;
        for (int i = 0; i < n; i++) {
            double S = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    S += A[i][j] * x[j];
                }
            }
            y[i] = (A[i][n] - S) / A[i][i];
        }
        
        for (int i = 0; i < n; i++) {
            if (fabs(x[i] - y[i]) >= E) {
                t = 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            x[i] = y[i];
        }
        
    } while (t);
}

void out() {
    printf("He phuong trinh co nghiem: {x, y, z, w, t} = {");
    for (int i = 0; i < 5; i++) {
        printf("%.2f", x[i]);
        if (i < 4)
            printf(", ");
    }
    printf("}\n");
}

int main() {
    xuly();
    out();
    return 0;
}
