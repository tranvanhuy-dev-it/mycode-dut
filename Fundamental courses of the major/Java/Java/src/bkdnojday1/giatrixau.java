package bkdnojday1;

import java.util.Scanner;

public class giatrixau {
    static final long MOD = 1000000007L;
    
    static long nd(long a) {
        return powMod(a, MOD - 2);
    }

    static long powMod(long a, long e) {
        long res = 1;
        while (e > 0) {
            if ((e & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String t = sc.next();   
        int n = t.length();

        long nd6 = nd(6);
        long ans = 0;
        for (int j = 1; j <= n; j++) {
            int val = t.charAt(j - 1) - 'a' + 1;
            long sum = (long) j * (j + 1) % MOD * (2L * j + 1) % MOD * nd6 % MOD;
            long res = (long) val * (n - j + 1) % MOD * sum % MOD;
            ans = (ans + res) % MOD;
        }

        System.out.println(ans);
    }
}
