//x^5 – 5x^3 + 2x^2 + 15x – 2006 = 0
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
    return (double)pow(x, 5) - 5*(double)pow(x, 3) + 2*x*x + 15*x - 2006;
}

double cal() {
    double a = 4, b = 5, c, E = 0.00000001;
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