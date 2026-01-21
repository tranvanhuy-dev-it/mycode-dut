package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai1 {

    static double max1(double a, double b, double c) {
        double max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        return max;
    }
    
    static double max2(double a, double b, double c) {
        if (a >= b && a >= c) return a;
        else if (b >= a && b >= c) return b;
        else return c;
    }
    
    static double max3(double a, double b, double c) {
        return (a >= b) ? ((a >= c) ? a : c) : ((b >= c) ? b : c);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Nhap so a: ");
        double a = Double.parseDouble(br.readLine());

        System.out.print("Nhap so b: ");
        double b = Double.parseDouble(br.readLine());

        System.out.print("Nhap so c: ");
        double c = Double.parseDouble(br.readLine());

        double result1 = max1(a, b, c);
        double result2 = max2(a, b, c);
        double result3 = max3(a, b, c);
        
        System.out.println("(Dung if): So lon nhat la: " + result1);
        System.out.println("(Dung if_else): So lon nhat la: " + result2);
        System.out.println("(Dung toan tu ?:): So lon nhat la: " + result3);
    }
}
