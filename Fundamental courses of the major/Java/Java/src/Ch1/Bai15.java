package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai15 {

    static boolean CheckSCP(int n) {
        double k = Math.sqrt(n);
        if (k * k == n) {
            return true;
        }
        else {
            return false;
        }
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Kiem tra So chinh phuong\nNhap P: ");
        int p = Integer.parseInt(br.readLine());
        
        boolean ok = CheckSCP(p);
        if (ok) {
            System.out.print("YES");
        }
        else {
            System.out.print("NO");
        }
    }
}
