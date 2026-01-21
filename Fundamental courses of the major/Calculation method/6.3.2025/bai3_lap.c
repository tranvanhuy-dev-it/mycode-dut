//x^5 – 5x^3 + 2x^2 + 15x – 2006 = 0 
#include<stdio.h>
#include<math.h>

double val(double x);
double cal();

int main() {
    double temp = cal();
    printf("Nghiem duong cua phuong trinh la: x=%.3lf\nf(%.3lf) = %lf\n", 
        temp, temp, pow(temp, 5) - 5*pow(temp, 3) + 2*temp*temp +15*temp - 2006);
    return 0;
}

double val(double x) {
    return (double)pow(5*x*x*x - 2*x*x - 15*x + 2006, (double)1/5);
}

double cal() {
    double x = 1, E = 0.000000001;
    do {
        x = val(x);
    } while(fabs(x - val(x)) > E);
    return x;
}