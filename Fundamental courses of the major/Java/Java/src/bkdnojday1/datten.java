package bkdnojday1;

import java.util.Scanner;

public class datten {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long n = sc.nextLong();
		
		StringBuilder sb = new StringBuilder();
		
		while (n > 0) {
			n--;
			long i = n % 26;
			sb.append((char)('a' + i));
			n = n / 26;
		}
		sb.reverse();
		System.out.println(sb.toString());

	}
}
