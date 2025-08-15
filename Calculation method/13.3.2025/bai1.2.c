//x^3 + x^2 -2x - 5 = 0
//Phuong phap day cung
#include<stdio.h>
#include<math.h>

double fx(double x) {
    return pow(x, 3) + pow(x, 2) - 2*x -5;
}

void xuly(double a, double b) {
    double E = 0.0001, x;
    do {
        x = a - (b - a) * fx(a) / (fx(b)  - fx(a));
        if (fx(x) * fx(a) < 0) {
            b = x;
        }
        else {
            a = x;
        }
    } while (fabs(fx(x)) > E);
    printf("x= %.3lf\nf(x)= %lf\n", x, fx(x));
}

int main() {
    xuly(1, 2);
    return 0;
}