//x^3 + x^2 - 2x -5
#include<stdio.h>
#include<math.h>

double val(double x);
double cal();

int main() {
    double temp = cal();
    printf("Nghiem duong cua phuong trinh la: x=%.3lf\nf(%.3lf) = %lf\n", temp, temp, temp*temp*temp + temp*temp - 2*temp - 5);
    return 0;
}

double val(double x) {
    return (double)pow(5 + 2*x -x*x, (double)1/3);
}

double cal() {
    double x = 1, E = 0.00000001;
    do {
        x = val(x);
    } while(fabs(x - val(x)) > E);
    return x;
}
