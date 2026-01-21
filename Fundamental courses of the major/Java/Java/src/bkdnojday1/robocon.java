package bkdnojday1;

import java.util.*;

public class robocon {
    static final int MOD = 1_000_000_007;
    static long[] gt, gt_nd;

    static long pow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    static long C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return gt[n] * gt_nd[k] % MOD * gt_nd[n - k] % MOD;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[][] a = new int[k + 1][2];
        for (int i = 0; i < k; i++) {
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
        }
        a[k][0] = m;
        a[k][1] = n;

        Arrays.sort(a, (u, v) -> u[0] != v[0] ? u[0] - v[0] : u[1] - v[1]);

        int max = m + n;
        gt = new long[max + 1];
        gt_nd = new long[max + 1];
        gt[0] = 1;
        for (int i = 1; i <= max; i++) gt[i] = gt[i - 1] * i % MOD;
        gt_nd[max] = pow(gt[max], MOD - 2);
        for (int i = max; i > 0; i--) gt_nd[i - 1] = gt_nd[i] * i % MOD;

        long[] dp = new long[k + 1];

        for (int i = 0; i <= k; i++) {
            int x = a[i][0], y = a[i][1];
            dp[i] = C(x + y - 2, x - 1);

            for (int j = 0; j < i; j++) {
                int x2 = a[j][0], y2 = a[j][1];
                if (x2 <= x && y2 <= y) {
                    int dx = x - x2;
                    int dy = y - y2;
                    dp[i] = (dp[i] - dp[j] * C(dx + dy, dx) % MOD + MOD) % MOD;
                }
            }
        }

        System.out.println(dp[k]);
    }
}
