package bkdnojday1;

import java.util.Scanner;
import java.util.Arrays;

public class chiahet {
	
    public static void main(String[] args) {
    	
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        int[] f = new int[k];
        Arrays.fill(f, -1);
        f[0] = 0;

        long S = 0;
        int l = 1, r = 1, max = 0;
        for (int i = 1; i <= n; i++) {
            long A = sc.nextLong();
            S += A;

            int du = (int) (S % k);

            if (f[du] == -1) {
                f[du] = i;
            } 
            else {
                int d = i - f[du];
                if (d > max) {
                    max = d;
                    l = f[du] + 1;
                    r = i;
                }
            }
        }
        System.out.println(l + " " + r);
    }
}
