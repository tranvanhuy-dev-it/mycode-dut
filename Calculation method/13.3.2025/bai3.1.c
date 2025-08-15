//x^5 – 5x^3 + 2x^2 + 15x – 2006 = 0 
//phuong phap tiep tuyen

#include<stdio.h>
#include<math.h>

double fx(double x) {
    return pow(x, 5) - 5*pow(x, 3) + 2*pow(x, 2) + 15*x - 2006;
}

double dh(double x) {
    return 5*pow(x, 4) - 15*pow(x, 2) + 4*x + 15;
}

void xuly() {
    double temp, x=5;
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