package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai12 {

    static int[] Cal(int n) {
        int sum = 0, mult = 1;
        while (n > 0) {
            int i = n % 10;
            sum += i;
            mult *= i;
            n = n / 10;
        }
        return new int[]{sum, mult};
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhap n: ");
        int n = Integer.parseInt(br.readLine());
        
        int[] result = Cal(n);
        System.out.print("Sum = " + result[0] + "\nMult = " + result[1]);
    }
}
