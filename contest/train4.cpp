#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[i+1]) cout << "O";
        if (a[i] > a[i+1]) cout << "M";
    }
    return 0;
}