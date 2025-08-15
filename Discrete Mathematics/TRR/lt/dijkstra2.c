#include<stdio.h>
#define maxn 101
#define inf 10000000

int n, m, out, A[maxn][maxn], cost[maxn], prev[maxn], T[maxn];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = inf;
        }
    }
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        A[u][v] = A[v][u] = w;
    }
    scanf("%d", &out);
}

void create() {
    for (int i = 1; i <= n; i++) {
        cost[i] = inf;
        prev[i] = -1;
        T[i] = 1;
    }
    cost[1] = 0;
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        int min = inf, index = -1;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && cost[j] < min) {
                min = cost[j];
                index = j;
            }
        }
        T[index] = 0;
        if (index == -1) break;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && A[index][j] < inf) {
                if (cost[index] + A[index][j] < cost[j]) {
                    cost[j] = cost[index] + A[index][j];
                    prev[j] = index;
                }
            }
        }
    }
}

void print(int out) {
    if (prev[out] != -1) {
        print(prev[out]);
        printf(" -> ");
    }
    printf("%d", out);
}

int main() {


    input();
    create();
    dijkstra();
    printf("Duong di: ");
    print(out);
    printf("\nChi chi: %d\n", cost[out]);
    return 0;
}