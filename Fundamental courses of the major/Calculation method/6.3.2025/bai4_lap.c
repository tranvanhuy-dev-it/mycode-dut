//x^7 – x^6 + 6x^4 – 2x^3 + 1 = 0 
#include<stdio.h>
#include<math.h>

double val(double x);
double val2(double x);
double cal();

int main() {
    double temp = cal();
    printf("Nghiem am cua phuong trinh la: x=%.3lf\nf(%.3lf) = %lf\n", temp, temp, val(temp));
    return 0;
}
//tinh f(x)
double val(double x) { 
    return pow(x, 7) - pow(x, 6) + 6*pow(x, 4) - 2*pow(x, 3) + 1;
}
//tinh f'(x)
double val2(double x) {
    return 7*pow(x, 6) - 6*pow(x, 5) + 24*pow(x, 3) - 6*pow(x, 2);
}

double cal() {
    double temp, x = -7, E = 0.000001;
    do {
        temp = x;
        x = x - 0.1 * val(x)/val2(x);
    } while(fabs(temp - x) > E);
    return x;
}
