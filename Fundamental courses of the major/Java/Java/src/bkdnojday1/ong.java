package bkdnojday1;

import java.util.Scanner;

public class ong {
	
	static long souoc(long n) {
		int res = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				if (i * i == n) res++;
				else res += 2;
			}
		}
		return res;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		long a[] = new long[N];
		long ans = 0;
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextLong();
			ans += a[i]*souoc(a[i]);
		}
		System.out.println(ans);
		
	}

}
