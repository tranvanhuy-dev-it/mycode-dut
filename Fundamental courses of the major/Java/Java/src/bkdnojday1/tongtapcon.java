package bkdnojday1;

import java.util.Scanner;

public class tongtapcon {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
        int b = sc.nextInt();
		int A[] = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = sc.nextInt();
		}
		
		int max = n*100;
		boolean[] dp = new boolean[max + 1];
		dp[0] = true;
		for (int x : A) {
			for (int s = max; s >= x; s--) {
				if (dp[s - x]) {
					dp[s] = true;
				}
			}
		}
		
		int count = 0;
	       for (int s = a; s <= b; s++) {
	           if (dp[s]) count++;
	       }

	     System.out.println(count);
	}

}
