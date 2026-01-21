#include<stdio.h>
#define maxn 101
#define inf 100000

int A[maxn][maxn], T[maxn];
int n, m, out;

struct Node{
    int cost, prev;
};

typedef struct Node NODE;
NODE V[maxn];

int input() {
    int u, v, w;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        A[u][v] = w;
        A[v][u] = w;
    }
    scanf("%d", &out);
}

void create() {
    for (int i = 1; i <= n; i++) {
        V[i].cost = inf;
        V[i].prev = -1;
        T[i] = 1;
    }
    V[1].cost = 0;
}

void DIJSKTRA(int x) {
    int index = -1, min = inf;
    T[x] = 0;
    for (int i = 1; i <= n; i++) {
        if (A[x][i] >= 0 && A[x][i] < inf) {
            if (V[x].cost + A[x][i] < V[i].cost) {
                V[i].cost = V[x].cost + A[x][i];
                V[i].prev = x;
            }
        } 
    }
    for (int i = 1; i <= n; i++) {
        if (T[i] == 1 && V[i].cost < min) {
            min = V[i].cost;
            index = i;
        } 
    }
    if (index != -1) DIJSKTRA(index);
}

void print(int x) {
    if (V[x].prev != -1){
        print(V[x].prev);
    }
    printf("%d -> ", x);
}

int main() {

    input();
    create();
    DIJSKTRA(1);
    printf("Duong di: ");
    print(out);
    printf("Chi phi: %d\n", V[out].cost);
    return 0;
}