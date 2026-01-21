package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai5 {

    static double cal(double a, double b, double c) {
        if (a <= b && a >= c || a >= b && a <= c) return a;
        else if (b <= a && b >= c || b >= a && b <= c) return b;
        else return c;
    }
    
    public static void main(String args[]) throws IOException{    
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhap so a: ");
        double a = Double.parseDouble(br.readLine());
        System.out.print("Nhap so b: ");
        double b = Double.parseDouble(br.readLine());
        System.out.print("Nhap so c: ");
        double c = Double.parseDouble(br.readLine());
        
        double result = cal(a, b, c);
        System.out.print("So trung gian la: " + result);
    }
}
