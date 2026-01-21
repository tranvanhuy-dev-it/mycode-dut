//x^4 - 3x^2 + 75x – 1000 = 0
#include<stdio.h>
#include<math.h>

double val(double x);
double cal();

int main() {
    double temp = cal();
    printf("Nghiem am cua phuong trinh la: x=%.3lf\nf(%.3lf) = %lf\n", temp, temp, val(temp));
    return 0;
}

double val(double x) {
    return x*x*x*x - 3*x*x + 75*x - 1000;
}

double cal() {
    double a = -7, b = -6, c, E = 0.0000001;
    do {
        c = (a + b) * 0.5;
        if (val(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }

    } while(fabs(a - b) > E);
    return c;
}