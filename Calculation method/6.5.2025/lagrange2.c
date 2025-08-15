#include<stdio.h>

double Wp(int x[], int val) {
    double result = 1;
    for (int i = 0; i < 5; i++) {
        if (val != x[i]) {
            result *= (val - x[i]);
        }
    }
    return result;
}

double Lagrange(int x[], double y[], double value) {
    double result = 0, w =1;

    for (int i = 0; i < 5; i++) {
        w = w*(value - x[i]);
    } 

    for (int i = 0; i < 5; i++) {
        double temp = y[i] / ((value - x[i]) * Wp(x, x[i]));
        result += temp;
    }
    return w * result;
}

int main() {

    int x[6] = {0, 1, 2, 3, 4, 5};
    double y[6] = {20,	16.2, 7.2, 0.2, 7.2, 45};

    double result1 = Lagrange(x, y, 1.5);
    double result2 = Lagrange(x, y, 3.1);

    printf("Cach 2: \n");
    printf("f(2.5) = %lf\nf(3.1) = %lf\n",result1, result2);
    
    return 0;
}