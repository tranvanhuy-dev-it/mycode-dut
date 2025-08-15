#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
const int maxn = 1001;

typedef struct edge{
    int u, v, w;
}edge;

int n, m;
int parent[maxn], size[maxn];

edge *edges;

void input(){
    scanf("%d %d", &n, &m);
    edges = (edge*)malloc(m*sizeof(edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
}
void make_set(){
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}
int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
int Union(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if(size[a] < size[b]) {
        int i = a;
        a = b;
        b = i;
    }
    parent[b] = a;
    size[a] += size[b];
    return true;
}
void kruskal(){
    int d = 0, found = 0;
    for (int i = 0; i < m-1; i++) {
        for (int j = i+1; j < m; j++) {
            if(edges[i].w > edges[j].w) {
                edge k = edges[i];
                edges[i] = edges[j];
                edges[j] = k;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if(found == n-1) {
            break;
        }
        if(Union(edges[i].u, edges[i].v)) {
            d+=edges[i].w;
            found+=1;
        }

    }
    printf("\n%d\n", d);
}
int main() {
    input();
    make_set();
    kruskal();
    return 0;
}
