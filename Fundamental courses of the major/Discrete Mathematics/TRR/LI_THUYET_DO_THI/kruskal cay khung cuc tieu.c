#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

const int maxn = 1001;
int n, m;
int parent[maxn], size[maxn];

typedef struct edge{ //canh cua do thi
    int u, v, w;
}edge;

typedef struct edgekruskal{ //canh cua cay khung
    int u, v, w;
}edgekruskal;

edge *edges;
edgekruskal *e;

void input() {
    scanf("%d %d", &n, &m);
    edges = (edge*)malloc(m*sizeof(edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
}

void make_set() {
    for ( int i = 1; i <= n; i++) {
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
    if (a == b) return false;
    if (size[a] < size[b]) {
        int i = a;
        a = b;
        b = i;
    }
    parent[b] = a;
    size[a] += size[b];
    return true;
}

void kruskal() {
    input();
    make_set();
    for (int i = 0; i < m-1; i++) {
        for (int j = i+1; j < m; j++) {
            if(edges[i].w > edges[j].w) {
                edge k = edges[i];
                edges[i] = edges[j];
                edges[j] = k;
            }
        }
    }
    int d = 0, found = 0;
    e = (edgekruskal*)malloc((n-1)*sizeof(edgekruskal));
    for (int i = 0; i <= m; i++) {
        if (found == n - 1) break; 
        if(Union(edges[i].u, edges[i].v)) {
            d+=edges[i].w;
            found += 1;
            e[found].u = edges[i].u;
            e[found].v = edges[i].v;
            e[found].w = edges[i].w;
        }
    }
    printf("Cay khung nho nhat la:\n");
    for (int i = 1; i <= (n-1); i++) {
        printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
    }
    printf("d=%d\n", d);
}

int main() {

    kruskal();
    return 0;
}