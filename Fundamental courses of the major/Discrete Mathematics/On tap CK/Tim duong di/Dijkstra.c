//Dijkstra
#include<stdio.h>
#define maxn 101
#define inf 1000000

int n, m, out;
int A[maxn][maxn], T[maxn], cost[maxn], prev[maxn];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
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

void Dijkstra() {
    for (int i = 1; i <= n; i++) {
        int min = inf, index = -1;
        for (int j = 1; j <= n; j ++) {
            if (T[j] == 1 && cost[j] < min) {
                min = cost[j];
                index = j;
            }
        }
        T[index] = 0;
        if (index == -1) break;
        for (int j = 1; j <= n; j++) {
            if (T[j] > 0 && A[index][j] < inf) {
                if (cost[index] + A[index][j] < cost[j]) {
                    cost[j] = cost[index] + A[index][j];  
                    prev[j] = index;
                }
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

    printf("Duong di: ");
    Out(out);
    printf("\nChi phi: ");
    printf("%d\n", cost[out]);
    return 0;
}
/*
10 19
1 2 1 
2 3 4
3 4 6
1 5 3
5 6 4
6 7 3
2 5 1
3 5 2
3 6 2
4 6 2
4 7 2
1 8 2
1 9 3
8 9 6
9 10 3
4 10 3
5 9 5
9 6 5
10 7 1
4
*/
/*
6 8
2 1 5
4 1 2
3 2 5
4 2 2
4 3 8
5 3 2
6 3 6
5 4 10
6 5 3
*/