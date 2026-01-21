//x^3 + x^2 - 2x -5
#include<stdio.h>
#include<math.h>

double val(double x);
double cal();

int main() {
    double temp = cal();
    printf("Nghiem duong cua phuong trinh la: x=%.3lf\nf(%.3lf) = %lf\n", temp, temp, val(temp));
    return 0;
}

double val(double x) {
    return sin(x)*cos(x)*(1+tan(x))*(1+cos(x)/sin(x));
}

double cal() {
    double a = 0.5, b = 0.1, c, E = 0.0000001;
    do {
        c = (a + b) * 0.5;
        if (val(c) < 0) {
            a = c;
        }
        else {
            b = c;
        }

    } while(fabs(a - b) > E);
    return c;
}