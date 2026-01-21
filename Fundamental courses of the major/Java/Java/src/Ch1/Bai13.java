package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai13 {

    static int[] Cal(int a, int b) {
        int A = a, B = b;
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        int ucln = a;
        int bcnn = (A * B) / ucln;
        return new int[]{ucln, bcnn};
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhap a: ");
        int a = Integer.parseInt(br.readLine());
        System.out.print("Nhap b: ");
        int b = Integer.parseInt(br.readLine());
        
        int[] result = Cal(a, b);
        System.out.print("UCLN = " + result[0] + "\nBCNN = " + result[1]);
    }
}
