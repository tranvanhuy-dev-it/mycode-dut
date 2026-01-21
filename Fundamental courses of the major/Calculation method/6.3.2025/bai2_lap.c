//x^4 - 3x^2 + 75x -1000
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
    return x*x*x*x - 3*x*x + 75*x -1000;
}
//tinh f'(x)
double val2(double x) {
    return 4*x*x*x - 6*x + 75;
}

double cal() {
    double temp, x = -7, E = 0.000001;
    do {
        temp = x;
        x = x - 0.1 * val(x)/val2(x);
    } while(fabs(temp - x) > E);
    return x;
}
