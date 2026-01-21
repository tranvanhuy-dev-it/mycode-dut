//x^3 + x^2 -2x - 5 = 0
//phuong phap tiep tuyen

#include<stdio.h>
#include<math.h>

double fx(double x) {
    return pow(x, 3) + pow(x, 2) - 2*x -5;
}

double dh(double x) {
    return 3*pow(x, 2) + 2*x - 2;
}

void xuly() {
    double temp, x=2;
    double E = 0.001;
    printf("x= %.3lf\nf(x)/f'(x)=%.3lf\n\n", x, fx(x)/dh(x));
    do {
        temp = x;
        x = x - fx(x)/dh(x);
        printf("x= %.3lf\nf(x)/f'(x)=%.3lf\n\n", x, fx(x)/dh(x));
    } while(fabs(temp - x) > E);
    printf("x= %.3lf\nf(x)= %lf\n", x, fx(x));
}

int main(){
    xuly();
    return 0;
}