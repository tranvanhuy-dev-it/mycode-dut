#include<bits/stdc++.h>

using namespace std;

bool check(int x, int y) 
{
    if (max(x, y) <= 2 * min(x, y) + 2) return true;
    else return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (check(a, b) && check(c-a, d-b)) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}