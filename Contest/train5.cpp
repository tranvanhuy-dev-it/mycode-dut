#include <bits/stdc++.h>

using namespace std;

int dfs(int u, vector<vector<int>>& adj) 
{
    int cnt = 1;
    for (int v : adj[u]) {
        cnt += dfs(v, adj);
    }
    return cnt;
}

int main() {

    int n;
    cin >> n;
    vector<int> b(n + 1);

    vector<vector<int>> adj(n + 1);
    vector<int> ceos;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == 0) {
            ceos.push_back(i);
        } else {
            adj[b[i]].push_back(i); 
        }
    }

    int bestCEO = -1, bestSize = -1;
    for (int ceo : ceos) {
        int size = dfs(ceo, adj);
        if (size > bestSize) {
            bestSize = size;
            bestCEO = ceo;
        }
    }

    cout << bestCEO << " " << bestSize << "\n";
    return 0;
}
