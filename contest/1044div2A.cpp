#include<bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while(t--) 
    {
        unordered_set<int> a;
        int n;
        cin >> n;
        int x;
        bool check = false;
        for (int i = 0; i < n; i++) 
        {
            cin >> x;
            if (a.count(x)) check = true;
            else  a.emplace(x);
        }
        if (!check) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}