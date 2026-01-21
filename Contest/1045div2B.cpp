#include <bits/stdc++.h>

using namespace std;

int main() 
{

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long mx = *max_element(a.begin(), a.end());

        while(gcd(a) == 1) {
            for (int i = 0; i < n; i++) 
        {
            if (a[i] < mx && gcd(mx, a[i]) == 1) a[i] += k;
        }
        }

        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
