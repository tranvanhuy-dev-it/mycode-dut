//x^5 – 5x^3 + 2x^2 + 15x – 2006 = 0 
//Phuong phap day cung
#include<stdio.h>
#include<math.h>

double fx(double x) {
    return pow(x, 5) - 5*pow(x, 3) + 2*pow(x, 2) + 15*x - 2006;
}

void xuly(double a, double b) {
    double E = 0.000000001, x;
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
    xuly(4, 5);
    return 0;
}