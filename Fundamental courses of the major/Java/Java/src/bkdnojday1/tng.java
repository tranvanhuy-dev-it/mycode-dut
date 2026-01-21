package bkdnojday1;

import java.util.*;

public class tng {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        double A = sc.nextDouble();
        double B = sc.nextDouble();
        double[] x = new double[N + 1];
        for (int i = 1; i <= N; i++) {
            x[i] = sc.nextDouble();
        }

        Arrays.sort(x, 1, N + 1);

        double[] dp = new double[N + 1];
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = 10000000000.0;

            for (int j = 1; j <= i; j++) {
                double radius = (x[i] - x[j]) / 2.0;
                double cost = dp[j - 1] + A + B * radius;
                dp[i] = Math.min(dp[i], cost);
            }
        }

        if (Math.abs(dp[N] - Math.round(dp[N])) < 1e-6) {
            System.out.println((long) dp[N]);
        } else {
            System.out.printf("%.1f\n", dp[N]);
        }

    }
}
