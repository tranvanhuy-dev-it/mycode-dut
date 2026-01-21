package bkdnojday1;

import java.util.Scanner;

public class chonqua {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) {
        	a[i] = sc.nextInt();
        }

        long[] dp = new long[n];

        dp[0] = a[0];
        if(n>=2) dp[1] = a[0]+a[1];
        if(n>=3) dp[2] = Math.max(dp[1], Math.max(a[0]+a[2], a[1]+a[2]));

        for(int i=3;i<n;i++){
            dp[i] = Math.max(dp[i-1], Math.max(dp[i-2]+a[i], dp[i-3]+a[i-1]+a[i]));
        }

        System.out.println(dp[n-1]);
    }
}
