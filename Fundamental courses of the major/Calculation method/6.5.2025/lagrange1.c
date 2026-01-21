#include<stdio.h>

double Lagrange(int x[], double y[], double value) {
    double result = 0;
    for (int i = 0; i < 5; i++) {
        double temp = y[i];
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                temp *= (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += temp;
    }
    return result;
}

int main() {

    int x[6] = {0, 1, 2, 3, 4, 5};
    double y[6] = {20,	16.2, 7.2, 0.2, 7.2, 45};

    double result1 = Lagrange(x, y, 1.5);
    double result2 = Lagrange(x, y, 3.1);

    printf("f(1.5) = %lf\nf(3.1) = %lf\n",result1, result2);
    
    return 0;
}