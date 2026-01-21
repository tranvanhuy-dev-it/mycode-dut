#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAXN 50001
#define MAXK 8

typedef long long ll;

ll dp[MAXN][MAXK];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int val[MAXN], col[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &col[i]);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int len = 1; len < k; len++) {
        ll pre_sum = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && val[i] > val[i - 1] && col[i] != col[i - 1]) {
                dp[i][len] = pre_sum;
            }
            pre_sum = (pre_sum + dp[i][len]) % MOD;
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = (res + dp[i][k - 1]) % MOD;
    }

    printf("%lld\n", res);
    return 0;
}