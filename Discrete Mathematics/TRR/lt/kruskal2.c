#include<stdio.h>
#include<stdlib.h>
#define maxn 101

int A[maxn][maxn], parent[maxn], size[maxn];
int n, m;

struct edge{
    int u, v, w;
};
typedef struct edge EDGE;

EDGE *e, *emin;

void input() {
    scanf("%d%d", &n, &m);
    e = (EDGE*)malloc(m*sizeof(struct edge));
    emin = (EDGE*)malloc((n - 1)*sizeof(struct edge));
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
    if (size[a] < size[b]) {
        int t = a;
        a = b;
        b = t;
    }
    size[a] += size[b];
    parent[b] = a;
    return 1;
}

void kruskal() {
    int d = 0, p = 0;
    for (int  i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (e[i].w > e[j].w) {
                struct edge t = e[i];
                e[i] = e[j];
                e[j] = t;
            } 
        }
    }
    for (int i = 0; i < m; i++) {
        if (p == n - 1) break;
        if (Uni(e[i].u, e[i].v)) {
            d += e[i].w;
            emin[p++] = e[i];
        }
    }
    printf("\nd = %d\n", d);
}


int main() {

    input();
    create();
    kruskal();
    for (int i = 0; i < n - 1; i++) {
        printf("%d %d %d\n", emin[i].u, emin[i].v, emin[i].w);
    }
    return 0;
}