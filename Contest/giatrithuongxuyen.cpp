#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(a[i]) != m.end())
        {
            m[a[i]]++;
        }
        else 
        {
            m.insert({a[i], 1});
        }
    }
    int res = 0;
    for (auto x : m)
    {
        if (x.second > 2)
        {
            res++;
        }
    }
    cout << res;
    return 0;
}