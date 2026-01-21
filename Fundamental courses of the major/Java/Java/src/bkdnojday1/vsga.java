package bkdnojday1;

import java.util.Scanner;

public class vsga {

	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int max = 0;
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
            if(a[i] > max) max = a[i];
        }

        long[] sum = new long[max + 1];
        for(int i=0;i<n;i++) {
        	sum[a[i]] += a[i];
        }

        long[] dp = new long[max + 1];
        dp[0] = sum[0];
        if(max>=1) dp[1] = Math.max(sum[0], sum[1]);

        for(int i=2;i<=max;i++){
            dp[i] = Math.max(dp[i-1], dp[i-2]+sum[i]);
        }

        System.out.println(dp[max]);
    }

}
