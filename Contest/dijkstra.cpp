#include <iostream>
#include <climits>
using namespace std;

const int maxn = 101;
const int inf = INT_MAX;

int n, m, out;
int A[maxn][maxn], T[maxn], cost[maxn], prev_node[maxn];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            A[i][j] = inf;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u][v] = A[v][u] = w;
    }

    cin >> out;
}

void create() {
    for (int i = 1; i <= n; i++) {
        cost[i] = inf;
        prev_node[i] = -1;
        T[i] = 1;
    }
    cost[1] = 0;
}

void Dijkstra() {
    for (int i = 1; i <= n; i++) {
        int min_cost = inf, index = -1;
        for (int j = 1; j <= n; j++) {
            if (T[j] == 1 && cost[j] < min_cost) {
                min_cost = cost[j];
                index = j;
            }
        }

        if (index == -1) break;

        T[index] = 0;

        for (int j = 1; j <= n; j++) {
            if (T[j] && A[index][j] < inf) {
                if (cost[index] + A[index][j] < cost[j]) {
                    cost[j] = cost[index] + A[index][j];
                    prev_node[j] = index;
                }
            }
        }
    }
}


void printWeightsOnPath(int node) {
    if (prev_node[node] != -1) {
        printWeightsOnPath(prev_node[node]);
        cout <<A[prev_node[node]][node] ;
    }
}

int main() {
    input();
    create();
    Dijkstra();
    printWeightsOnPath(out);


    return 0;
}
