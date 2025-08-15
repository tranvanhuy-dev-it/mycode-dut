#include<stdio.h>

#define inf 1000000
#define N 6

int A[N][N] = {
    {inf, inf, 5, 44, 324, inf},
    {inf, 2, 21, inf, inf, inf},
    {2, 4, 5, inf, inf, 1},
    {3, inf, inf, inf, 2, 65},
    {inf, inf, inf, 5, 4, 8},
    {2, inf, inf, 3, inf, 1}
};

int T[N];

typedef struct Node{
    int cost;
    int prev;
}Node;

typedef Node NODE;

void khoitao(NODE V[]){
    for (int i = 0; i < N; i++) {
        V[i].cost = inf;
        V[i].prev = -1;
        T[i] = 1;
    }
}

void dijstra(int x, NODE V[]) {
    int min = inf, index, i;
    T[x] = 0;
    for (i = 0; i < N; i++){
        if(A[x][i] > 0 && A[x][i] < inf) {
            if (V[x].cost + A[x][i] < V[i].cost) {
                V[i].cost = V[x].cost + A[x][i];
                V[i].prev = x;
            }
        }
    }

    for (i = 0; i < N; i++) {
        if (T[i] == 1 && V[i].cost < min) {
            min = V[i].cost;
            index = i;
        }
    }

    if (min != inf) dijstra(index, V);
}


int main() {
    NODE V[N];
    khoitao(V);
    V[0].cost = 0;
    dijstra(0, V);
    printf("%d\n", V[4].cost);
    return 0;
}