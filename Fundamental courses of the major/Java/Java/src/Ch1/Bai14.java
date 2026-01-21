package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai14 {

    static boolean CheckSNT(int n) {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Kiem tra So nguyen to\nNhap n: ");
        int m = Integer.parseInt(br.readLine());
        
        boolean ok = CheckSNT(m);
        if (ok) {
            System.out.print("YES");
        }
        else {
            System.out.print("NO");
        }
    }
}
