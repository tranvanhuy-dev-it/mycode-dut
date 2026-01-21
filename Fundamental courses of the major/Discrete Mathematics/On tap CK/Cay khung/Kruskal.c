//Kruskal
#include<stdio.h>
#include<stdlib.h>
#define maxn 101

struct edge{
    int u, v, w;
};
typedef struct edge EDGE;

EDGE *e;
EDGE *emin;
int n, m, parent[maxn], size[maxn];

void input() {
    scanf("%d%d", &n, &m);
    e = (EDGE*)malloc((m+1)*sizeof(struct edge));
    for (int i = 1; i <= m; i++) {
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

int Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (size[a] < size[b]) {
        int t = a;
        a = b;
        b = t;
    }
    parent[b] = a;
    size[a] += size[b];
    return 1;
}

void Kruskal() {
    int d = 0, p = 0;
    for (int i = 1; i <= m - 1; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (e[i].w > e[j].w) {
                EDGE t = e[i];
                e[i] = e[j];
                e[j] = t;
            }
        }
    }
    emin = (EDGE*)malloc(sizeof(struct edge));
    for (int i = 1; i <= n; i++) {
        if (p == n-1) break;
        if (Union(e[i].u, e[i].v)) {
            d += e[i].w;
            p++;
            emin[p] = e[i];
        }
    }
    printf("\nd = %d\n", d);
    for(int i = 1; i <= p; i++) {
        printf("%d %d %d\n", emin[i].u, emin[i].v, emin[i].w);
    }
}

int main() {

    input();
    create();
    Kruskal();
    return 0;
}