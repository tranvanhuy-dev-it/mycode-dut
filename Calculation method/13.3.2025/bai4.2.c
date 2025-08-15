//x^7 – x^6 + 6x^4 – 2x^3 + 1 = 0 
//Phuong phap day cung
#include<stdio.h>
#include<math.h>

double fx(double x) {
    return pow(x, 7) - pow(x, 6) + 6*pow(x, 4) - 2*pow(x, 3) + 1;
}

void xuly(double a, double b) {
    double E = 0.000000001, x=-2;
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
    xuly(-2, -1);
    return 0;
}