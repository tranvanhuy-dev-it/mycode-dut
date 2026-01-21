//x^7 – x^6 + 6x^4 – 2x^3 + 1 = 0
#include<stdio.h>
#include<math.h>

double val(double x);
double cal();

int main() {
    double temp = cal();
    printf("Nghiem am cua phuong trinh la: x=%.3lf\nf(%.3lf) = %lf\n", 
        temp, temp, val(temp));
    return 0;
}

double val(double x) {
    return (double)pow(x, 7) - (double)pow(x, 6) + 6*(double)pow(x, 4) - 2*x*x*x + 1;
}

double cal() {
    double a = -2, b = -1, c, E = 0.0000001;
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