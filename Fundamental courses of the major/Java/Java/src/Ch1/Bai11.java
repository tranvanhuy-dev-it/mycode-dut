package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai11 {

    static double Cal(int n) {
        double result = 1;
        if (n % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 0) {
                    result *= i;
                }
            }
        }  
        else {
            for (int i = 1; i <= n; i++) {
                if (i % 2 != 0) {
                    result *= i;
                }
            }
        }            
        return result;
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhap n: ");
        int n = Integer.parseInt(br.readLine());
        
        double result = Cal(n);
        System.out.print(n + "!! = " + result);
    }
}
