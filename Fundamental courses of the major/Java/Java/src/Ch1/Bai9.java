package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai9 {

    static double Cal(int n) {
        double result = 15;
        double gt = 1;
        for (int i = 1; i <= n; i++) {
            gt = gt * i;
            result += Math.pow(-1, i) / gt;
        }    
        return result;
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhap n: ");
        int n = Integer.parseInt(br.readLine());
        
        double result = Cal(n);
        System.out.print("QK = " + result);
    }
}
