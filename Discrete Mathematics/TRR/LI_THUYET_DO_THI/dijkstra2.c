#include<stdio.h>
#define maxn 100
#define inf 1000000
#define ll long long

ll A[maxn][maxn], T[maxn], cost[maxn], prev[maxn];
ll n, m, out;

void input() {
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            A[i][j] = inf;
        }
    }
    for (ll i = 1; i <= m; i++) {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        A[u][v] = A[v][u] = w;
    }
}

void create() {
    for (ll i = 1; i <= n; i++) {
        cost[i] = inf;
        prev[i] = -1;
        T[i] = 1;
    }
    cost[1] = 0;
}

void dijkstra() {
    for (ll i = 1; i <= n; i++) {
        ll index = -1, min = inf;
        for (ll j = 1; j <= n; j++) {
            if (T[j] == 1 && cost[j] < min) {
                index = j;
                min = cost[j];
            }
        }
        T[index] = 0;
        for (ll j = 1; j <= n; j++) {
            if (T[j] == 1 && A[index][j] < inf) {
                if (cost[index] + A[index][j] < cost[j]) {
                    cost[j] = cost[index] + A[index][j];
                    prev[j] = index;
                }
            }
        }
    }
}

void print(ll n) {
    if (prev[n] != -1) {
        print(prev[n]);
    }
    printf("%d ", n);
}


int main() {

    input();
    create();
    dijkstra();
    if (m == 1) {
        printf("-1");
    }
    else if (cost[n] == inf) {
        printf("-1");
    } else {
        printf("%lld\n", cost[n]);
        print(n);
        printf("\n");
    }
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
5
*/