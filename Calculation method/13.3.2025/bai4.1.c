
//x^7 – x^6 + 6x^4 – 2x^3 + 1 = 0 
//phuong phap tiep tuyen

#include<stdio.h>
#include<math.h>

double fx(double x) {
    return pow(x, 7) - pow(x, 6) + 6*pow(x, 4) - 2*pow(x, 3) + 1;
}

double dh(double x) {
    return 7*pow(x, 6) - 6*pow(x, 5) + 24*pow(x, 3) - 6*pow(x, 2);
}

void xuly() {
    double temp, x=-2;
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