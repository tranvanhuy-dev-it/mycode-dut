#include<stdio.h>
#include<math.h>
#define maxn 101
#define E 0.001

int n;
double A[maxn][maxn], x[maxn], R[maxn];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            scanf("%lf", &A[i][j]);
        }
        x[i] = 0.0;
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        printf("x%d = %0.3lf ", i, x[i]);
    }
    printf("      ");
    for (int i = 1; i <= n; i++) {
        printf("r%d = %0.3lf ", i, R[i]);
    }
    printf("\n");
}

void create() {
    for (int i = 1; i <= n; i++) {
        R[i] = A[i][n + 1] / A[i][i];
    }
    for (int i = 1; i <= n; i++) {
        double t = A[i][i];
        for (int j = 1; j <= n + 1; j++) {
            A[i][j] /= t;
        }
    }
}

void lap() {
    int t;
    do {
        t = 0;
        int k = 1;
        double max = R[1];
        for ( int i = 2; i <= n; i++) {
            if (fabs(R[i]) > max) {
                max = fabs(R[i]);
                k = i;
            }
        }
        x[k] += R[k];
        output();
        double d = R[k];
        for (int i = 1; i <= n; i++) {
            R[i] = R[i] - A[i][k] * d;
            if (fabs(R[i]) > E) {
                t = 1;
            }
        }

    }while(t);
}

int main() {
    input();
    create();
    lap();
    return 0;
}

/*testcase
3
4 -1 0 3
-1 4 -1 1
0 -1 4 2
*/
