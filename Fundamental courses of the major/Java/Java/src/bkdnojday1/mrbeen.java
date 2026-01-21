package bkdnojday1;

import java.util.Scanner;

public class mrbeen {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		long C = sc.nextLong();
		int k = sc.nextInt();
		
		if (k == 0) {
		    System.out.print(C);
		    return;
		}
		
		long m = 1;                                                  
        for (int i = 0; i < k; i++) {
        	m *= 10;
        }
        
        long du = C % m;
		if (du >= (m + 1) / 2 ) {
			C = C + (m - du);
		} else {
			C = C - du;
		}
		System.out.print(C);
	}
}
