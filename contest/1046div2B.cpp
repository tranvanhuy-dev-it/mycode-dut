#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<int> dp(n+1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            unordered_map<int,int> cnt;

            for (int j = i; j >= 1 && i - j + 1 <= 100; j--) {
                cnt[a[j]]++;
                if (cnt[a[j]] == a[j]) {
                    dp[i] = max(dp[i], dp[j-1] + a[j]);
                }
            }
        }
        cout << dp[n] << "\n";
    }
}
