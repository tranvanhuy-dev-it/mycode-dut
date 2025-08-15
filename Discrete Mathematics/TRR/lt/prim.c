#include<stdio.h>
#define maxn 101
#define inf 10000000

int n, m, A[maxn][maxn], T[maxn], prev[maxn], cost[maxn];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = inf;
        }
    }
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        A[u][v] = A[v][u] = w;
    }
}

void create() {
    for (int i = 1; i <= n; i++) {
        cost[i] = inf;
        prev[i] = -1;
        T[i] = 1;
    }
    cost[1] = 0;
}

void prim() {
    int d = 0;
    for (int i = 1; i <= n; i++) {
        int min = inf, index = -1;
        for (int j = 1; j <= n; j++) {
            if (T[j] ==1 && cost[j] < min) {
                min = cost[j];
                index = j;
            }
        }
        T[index] = 0;
        d += cost[index];
        if (index == -1) break;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && A[index][j] < inf) {
                if (A[index][j] < cost[j]) {
                    cost[j] = A[index][j];
                    prev[j] = index;
                }
            }
        }
    }
    printf("\nd = %d\n", d);
}

int main() {

    input();
    create();
    prim();
    for (int i = 2; i <= n; i++) {
        printf("%d %d %d\n", prev[i], i, A[prev[i]][i]);
    }
    return 0;
}

/*
5 7
1 2 2
1 3 5
2 3 1
2 4 3
3 4 1
3 5 7
4 5 4
*/