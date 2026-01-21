#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool check = true;
    for (long long i = 0; i < n/2; i++) 
    {
        if (a[i] != a[n-i-1]) check = false;
    }
    if (check) cout << "YES";
    else cout << "NO";

    return 0;
}
