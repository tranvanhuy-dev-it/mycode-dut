package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai16 {

    static boolean CheckSDX(int n) {
        int temp = n, dao = 0;
        while ( n > 0) {
            dao = dao * 10 + n % 10;
            n = n / 10;
        }
        if (dao == temp) return true;
        else return false;
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Kiem tra So doi xung\nNhap M: ");
        int m = Integer.parseInt(br.readLine());
        
        boolean ok = CheckSDX(m);
        if (ok) {
            System.out.print("YES");
        }
        else {
            System.out.print("NO");
        }
    }
}
