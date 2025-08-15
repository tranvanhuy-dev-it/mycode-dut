#include<stdio.h>
#include<stdlib.h>
#define inf 100000

int n, m, start, out, cost[101], prev[101], A[101][101];

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
        A[u][v] = w;
    }
    scanf("%d%d", &start, &out);
}

void create() {
    for (int i = 1; i <= n; i++) {
        cost[i] = inf;
        prev[i] = -1;
    }
    cost[start] = 0;
}

void bellmanford(int start) {

    for (int i = 1; i <= n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (A[u][v] < inf && cost[u] + A[u][v] < cost[v]) {
                    cost[v] = cost[u] + A[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (A[u][v] < inf && cost[u] + A[u][v] < cost[v]) {
                printf("Do thi co chu trinh am!\n");
                exit(0);
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
    bellmanford(start);
    printf("Chi phi: %d\n", cost[out]);
    printf("Duong di: "); print(out);printf("\n");
    return 0;
}
/*
5 8
1 2 6
1 3 7
2 3 8
2 4 5
2 5 -4
3 4 -3
3 5 9
4 2 -2
2 5
*/