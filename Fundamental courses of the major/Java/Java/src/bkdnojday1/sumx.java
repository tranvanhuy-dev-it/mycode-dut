package bkdnojday1;

import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays;

public class sumx {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int x = sc.nextInt();
		int a[] = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		
		Arrays.sort(a);
		
		int i = 0;
		int j = N - 1;
		int cnt = 0;
		while (i < j) {
			if (a[i] + a[j] == x) {
				cnt++;
				i++;
				j--;
			} else if (a[i] + a[j] < x) {
				i++;
			} else {
				j--;
			}
		}
		System.out.println(cnt);
	}

}
