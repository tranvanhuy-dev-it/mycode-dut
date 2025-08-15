#include <stdio.h>
#include <math.h>

double val(double x);
double cal();

int main() {
    double temp = cal();
    printf("Nghiệm âm của phương trình là: x=%.6lf\nf(%.6lf) = %lf\n", 
        temp, temp, pow(temp, 7) - pow(temp, 6) + 6*pow(temp, 4) - 2*pow(temp, 3) + 1);
    return 0;
}

double val(double x) {
    return pow(fabs(pow(x, 6) - 6*pow(x, 4) + 2*pow(x, 3) + 1), 1.0/7);
}

double cal() {
    double x = -1, E = 1e-9, x_next;
    do {
        x_next = val(x);
    } while (fabs(x - x_next) > E && (x = x_next));
    return x;
}
