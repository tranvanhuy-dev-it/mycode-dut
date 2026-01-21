package bkdnojday1;

import java.util.*;

public class muatra {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int Q = sc.nextInt();

        long[] c = new long[n];
        for (int i = 0; i < n; i++) {
        	c[i] = sc.nextLong();
        }
        Arrays.sort(c);
        long[] p = new long[n + 1];
        for (int i = 0; i < n; i++) {
        	p[i + 1] = p[i] + c[i];
        }
        
        while (Q-- > 0) {
            long k = sc.nextLong();
            int m = sc.nextInt();

            int vt = Arrays.binarySearch(c, k);
            if (vt < 0) vt = -vt - 1;

            long ans = Long.MAX_VALUE;

            int min = Math.max(0, m - (n - vt));
            int max = Math.min(m, vt);

            for (int x : new int[]{min, max}) {
                if (x < min || x > max) continue;

                long sumA = p[x];
                long sumB = (m - x) * 2L * k - (p[n] - p[n - (m - x)]);

                ans = Math.min(ans, sumA + sumB);
            }

            System.out.println(ans);
        }
    }
}

