#include <stdio.h>

#define maxn 101
#define inf 100000

typedef struct Node {
    int cost;
    int prev;
} Node;

typedef Node NODE;

void input(int *n, int *m, int *u_in, int *u_out, int A[][maxn]) {
    int u, v, w;
    scanf("%d %d", n, m);
    for (int i = 1; i <= *n; i++) {
        for (int j = 1; j <= *n; j++) {
            A[i][j] = inf;
        }
    }
    for (int i = 1; i <= *m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        A[u][v] = w;
    }
    scanf("%d %d", u_in, u_out);
}

void create(NODE V[], int n, int T[]) {
    for (int i = 1; i <= n; i++) {
        V[i].cost = inf;
        V[i].prev = -1;
        T[i] = 1;
    }
}

void Dijstra(int n, int A[][maxn], NODE V[], int T[], int x) {

    V[x].cost = 0;
    T[x] = 0;
    for (int i = 1; i <= n - 1; i++) {
        int min = 1000, index = -1;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && V[j].cost < min) {
                min = V[j].cost;
                index = j;
            }
        }
        if (index == -1) break;
        T[index] = 0;
        for (int j = 1; j <= n; j++) {
            if (A[index][j] != inf && V[index].cost + A[index][j] < V[j].cost) {
                V[j].cost = V[index].cost + A[index][j];
                V[j].prev = index;
            }
        }
    }
}

int main() {
    NODE V[maxn];
    int n, m, u_in, u_out;
    int A[maxn][maxn];
    int T[maxn];
    input(&n, &m, &u_in, &u_out, A);
    Dijstra(n, A, V, T, u_in);
    printf("%d\n", V[u_out].cost);
    return 0;
}