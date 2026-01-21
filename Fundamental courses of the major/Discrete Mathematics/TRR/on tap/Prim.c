#include<stdio.h>
#define maxn 101
#define inf 10000000

int n, m, A[maxn][maxn], T[maxn], cost[maxn], prev[maxn];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = inf;
        }
    }
    int u, v, w;
    for (int i = 1;  i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        A[u][v] = A[v][u] = w;
    }
}

void create() {
    for (int i = 1; i <= n; i++) {
        cost[i] = inf;
        T[i] = 1;
    }
    cost[1] = 0;
}

int Prim() {
    int d = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, min = inf;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && cost[j] < min){
                min = cost[j];
                u = j;
            }
        }
        T[u] = 0;
        d += cost [u];
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && A[u][j] < cost[j]){
                cost[j] = A[u][j];
                prev[j] = u;
            }
        }
    }
    return d;
}

int main() {

    input();
    create();
    printf("\nd = %d\n", Prim());
    for (int i = 2; i <= n; i++) {
        printf("%d %d %d\n", prev[i], i, A[prev[i]][i]);
    }
    return 0;
}