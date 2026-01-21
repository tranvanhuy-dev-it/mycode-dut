#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long sum = 0;
    long long res = 0;
    long long right = 0;

    for (int left = 0; left < n; left++)
    {
        while (right < n && sum < k)
        {
            sum += a[right];
            right++;
        }
        if (sum >= k)
        {
            res += n - right + 1;
        }
        sum -= a[left];
    }

    cout << res << endl;
    return 0;
}
