#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = 0;
    int index = 0;
    int i = 1;
    while (i != n) 
    {
        if (a[i] - a[index] <= m && i - index + 1 <= k) i++;
        else
        {
            res++;
            index = i;
            i++;
        }
        
    }
    cout << res + 1 << endl;
    return 0;
}