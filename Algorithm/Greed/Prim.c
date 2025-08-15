#include<stdio.h>
#include<math.h>
#define maxn 100
#define inf 1000000

int n, m, A[maxn][maxn], cost[maxn], prev[maxn], T[maxn];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=  n; j++) {
            A[i][j] = inf;
        }
    }
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        A[u][v] = A[v][u] = w;
    }
}

void create() {
    for (int i = 1; i <= n; i++) {
        cost[i] = inf;
        prev[i]= -1;
        T[i] = 1;
    }
    cost[1] = 0;
}

int Prim() {
    int d = 0;
    for (int i = 1; i <= n; i++) {
        int index = -1, min = inf;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && cost[j] < min) {
                min = cost[j];
                index = j;
            }
        }
        T[index] = 0;
        d += cost[index];
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && A[index][j] < cost[j]) {
                cost[j] = A[index][j];
                prev[j] = index;
            }
        }
    }
    return d;
}

int main() {

    input();
    create();
    int d = Prim();
    printf("\nd = %d\n", d);
    for (int i = 2; i <= n; i++) {
        printf("%d %d %d\n", prev[i], i, A[prev[i]][i]);
    }
    return 0;
}