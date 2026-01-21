#include <stdio.h>
#define maxn 101
#define inf 100000

typedef struct Node {
    int cost;
    int prev;
} Node;

typedef Node NODE;

NODE V[maxn];
int n, m, u_out, p = 1;
int A[maxn][maxn];
int T[maxn];

void input() {
    int u, v, w;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        A[u][v] = w;
        A[v][u] = w;
    }
    scanf("%d", &u_out);
}

void create() {
    for (int i = 1; i <= n; i++) {
        V[i].cost = inf;
        V[i].prev = -1;
        T[i] = 1;
    }
    V[1].cost = 0;
}

void Dijkstra(int x) {
    int min = inf, index = -1, i;
    T[x] = 0;
    for (i = 1; i <= n; i++){
        if(A[x][i] >= 0 && A[x][i] < inf) {
            if (V[x].cost + A[x][i] < V[i].cost) {
                V[i].cost = V[x].cost + A[x][i];
                V[i].prev = x;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (T[i] == 1 && V[i].cost < min) {
            min = V[i].cost;
            index = i;
        }
    }

    if (min != inf) Dijkstra(index);
}

void print(int i) {
    if (V[i].prev != -1)
        print(V[i].prev);
    printf("%d -> ", i);
}

int main() {
    input();
    create();
    Dijkstra(1);
    printf("%d\n", V[u_out].cost);
    if (V[u_out].cost < inf) {
        printf("Duong di: ");
        print(u_out); printf("Chi phi: %d\n", V[u_out].cost);

    } else {
        printf("Khong co duong di\n");
    }
    return 0;
}
