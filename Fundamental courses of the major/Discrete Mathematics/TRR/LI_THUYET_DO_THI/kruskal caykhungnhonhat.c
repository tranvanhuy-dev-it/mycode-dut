#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

//thuoc tinh cua canh
struct edge{
    int u; //dinh dau
    int v; //dinh cuoi
    int w; //trong so
};

const int maxn = 1001; //so dinh lon nhat
struct edge *edges;
int n; //dinh
int m; //canh

int parent[maxn]; //cha
int size[maxn];

void make_set() { // khoi tao va tao cha cho cac dinh
    for (int i = 1; i <= n; i++) {
        parent[i] = i; //cha cua dinh i
        size[i] = 1; //so phan tu co trong goc i
    }
}

int find(int v) {
    if (v == parent[v]) return v; //neu v la goc cua chinh no tra ve v
    return parent[v] = find(parent[v]);//neu khong thi tim cha cua v
}

int Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false; //neu cung cha thi khong can hop nhat
    if(size[a] < size[b]) { //neu so phan tu co trong a be hon b thi b la cha cua a
        int i = a;
        a = b;
        b = i;
    }
    parent[b] = a; // sau khi hop nhat thi cha cua b la a
    size[a] += size[b];
    return true;
}

void input() {
    scanf("%d %d", &n, &m); // nhap so luong dinh va so luong canh
    edges = (struct edge*)malloc(m*sizeof(struct edge));
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
}

void kruskal( ){
    int d = 0, found = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i+1; j < m; j++) {
            if(edges[i].w > edges[j].w) {
                struct edge t = edges[i];
                edges[i] = edges[j];
                edges[j] = t;
            }
        }
    } // sap xep

    for (int i = 0; i < m; i++) {
        if (found == n-1) break;
        struct edge e = edges[i];
        if(Union(e.u, e.v)) {
            d+=e.w;
            found+=1;
        }
    }
    if (found != n - 1) {
        printf("Error!\n");
    }
    printf("\n%d\n", d);

    
}

int main() {

    input();
    make_set();
    kruskal();
    return 0;
}