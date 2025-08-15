#include<stdio.h>
#include<math.h>

int giaithua(int i) {
    if (i == 0 || i == 1) return 1;
    return giaithua(i - 1)*i;
}

int tohop(int k, int n) {
    return giaithua(n) / (giaithua(k) *giaithua(n - k));
}

double Lagrange(int n, double x[], double y[], double c) {
    double h = x[1] - x[0];
    double t = (c - x[0]) / h;

    double W = 1;
    for (int i = 0; i <= n; i++) {
        W *= (t - i);
    }
    W = W / giaithua(n);

    double temp = 0;
    for (int i = 0; i <= n; i++) {
        if (fabs(t - i) < 1e-10) continue;
        int j = n - i;
        if (j % 2 == 0) { 
            temp += y[i] * tohop(i, n) / (t - i);
        } else {
            temp -= y[i] * tohop(i, n) / (t - i);
        }
    }
    return W * temp;
}

int main() {

    double x[] = {1, 3, 5, 7, 9, 11};
    double y[] = {2, 6, 15, 26, 47, 78};
    int n = 5;
    double c;
    printf("Nhap vao gia tri muon tinh: ");
    scanf("%lf", &c);
    printf("f(%lf) = %lf\n", c, Lagrange(n, x, y, c));
    return 0;
}