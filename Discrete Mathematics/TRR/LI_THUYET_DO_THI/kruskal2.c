#include<stdio.h>
#include<stdlib.h>
#define maxn 100

struct edge{
    int u, v, w;
};

typedef struct edge  EDGE;

EDGE *e, *emin;

int n, m, A[maxn][maxn], parent[maxn], size[maxn];

void input() {
    scanf("%d%d", &n, &m);
    e = (EDGE*)malloc(m*sizeof(struct edge));
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
}

void create() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

int Uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    parent[b] = a;
    size[a] += size[b];
    return 1;
}

void kruskal() {
    int d = 0, p = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (e[i].w > e[j].w) {
                EDGE t = e[i];
                e[i] = e[j];
                e[j] = t;
            }
        }
    }
    emin = (EDGE*)malloc((n-1) * sizeof(struct edge));
    for (int i = 0; i < m - 1; i++) {
        if (p == n - 1) break;
        if (Uni(e[i].u, e[i].v)) {
            d += e[i].w;
            emin[p] = e[i];
            p++;
        }
    }
    printf("\nd = %d\n", d);
    for (int i = 0; i < n - 1; i++) {
        printf("%d %d %d\n", emin[i].u, emin[i].v, emin[i].w);
    }
}

int main() {

    input();
    create();
    kruskal();
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