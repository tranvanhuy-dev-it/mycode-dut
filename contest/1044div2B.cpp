#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<long long> g(n);
        long long sum = 0, mx = 0;
        for (int i = 0; i < n; i++) 
        {
            cin >> g[i];
            sum += g[i];
            mx = max(mx, g[i]);
        }

        if (n == 2) 
        {
            cout << mx << endl;
        } 
        else 
        {
            long long r = (sum + (n - 2)) / (n - 1); 
            cout << max(mx, r) << endl;
        }
    }
    return 0;
}


// 4
// 2
// 1 2
// 4
// 2 1 5 2
// 5
// 1000000000 1000000000 1000000000 1000000000 1000000000
// 6
// 3 1 4 1 5 9
