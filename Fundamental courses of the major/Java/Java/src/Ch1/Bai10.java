package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai10{
    
    static double gt(int n) {
        double result = 1;
        for (int i = 1; i <= n; i++) {
            result = result * i;
        }
        return result;
    }

    static double Cal(int n) {
        double result = 0;
        for (int i = 1; i <= n; i++) {
            result += 1.0 / gt(2 * i - 1);
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
