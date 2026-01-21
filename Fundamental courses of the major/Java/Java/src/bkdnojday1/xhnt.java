package bkdnojday1;

import java.util.Scanner;
import java.util.HashSet;

public class xhnt {
	
    public static void main(String[] args) {
    	// TODO Auto-generated method stub
    	Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();

        for (int k = 1; k <= N; k++) {
            HashSet<String> doancon = new HashSet<>();
            boolean ok = true;
            for (int i = 0; i + k <= N; i++) {
                String conmoi = S.substring(i, i + k);
                if (doancon.contains(conmoi)) {
                    ok = false;
                    break;
                }
                doancon.add(conmoi);
            }
            if (ok) {
                System.out.println(k);
                break;
            }
        }
    }
}
