#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long x, sum = 0, res = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> x;
        sum += x;
        res = min(res, sum);
    }
    cout << max(0LL, -res);
}