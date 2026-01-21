#include<stdio.h>

#define maxn 100
#define inf 1000000

int n, m, out, A[maxn][maxn], T[maxn], cost[maxn], prev[maxn];

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
    scanf("%d", &out);
}

void create() {
    for (int i = 1; i <= n; i++) {
        cost[i] = inf;
        T[i] = 1;
        prev[i] = -1;
    }
    cost[1] = 0;
}

void Dijkstra() {
    for (int i = 1; i <= n; i++) {
        int index = -1, min = inf;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && cost[j] < min) {
                index = j;
                min = cost[j];
            }
        }
        T[index] = 0;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && cost[index] + A[index][j] < cost[j]) {
                cost[j] = cost[index] + A[index][j];
                prev[j] = index;
            }
        }
    }
}

void Out(int out) {
    if (prev[out] != -1) {
        Out(prev[out]);
        printf(" -> ");
    }
    printf("%d", out);
}

int main() {

    input();
    create();
    Dijkstra();
    printf("Duong di: "); Out(out);
    printf("\nChi phi: %d\n", cost[out]);
    return 0;
}