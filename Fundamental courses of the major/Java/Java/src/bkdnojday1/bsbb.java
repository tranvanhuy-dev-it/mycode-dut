package bkdnojday1;

import java.util.Scanner;

public class bsbb {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = 0;
        
        for (int a = 1; a < n; a++) {
            cnt += (n - 1) / a; 
        }
        System.out.println(cnt);
    }
}
