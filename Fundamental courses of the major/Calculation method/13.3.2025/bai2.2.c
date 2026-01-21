//x^4 - 3x^2 + 75x – 1000 = 0
//Phuong phap day cung
#include<stdio.h>
#include<math.h>

double fx(double x) {
    return pow(x, 4) - 3*pow(x, 2) + 75*x - 1000;
}

void xuly(double a, double b) {
    double E = 0.001, x;
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
    xuly(-7, -6);
    return 0;
}