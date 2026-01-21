package bkdnojday1;

import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays;

public class bai1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int M = sc.nextInt();
		int N = sc.nextInt();
		long a[] = new long[N];
		long sum = 0;
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextLong();
			sum += a[i];
		}
		long t = sum - M;
		Arrays.sort(a);
		BigInteger ans = BigInteger.ZERO;
		for (int i = 0; i < N; i++) {
			long x = t / (N - i);
			if (a[i] < x) {
				ans = ans.add(new BigInteger(a[i]*a[i]+""));
				t -= a[i];
			} else {
				ans = ans.add(new BigInteger(x*x+""));
				t -= x;
			}
			sum -= a[i];
			M--;
		}
		System.out.println(ans);
		
	}

}
