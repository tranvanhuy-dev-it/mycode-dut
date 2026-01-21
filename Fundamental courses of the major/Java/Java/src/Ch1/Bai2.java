package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai2 {

    static void cal(double a, double b) {
        if (a == 0 && b == 0) {
            System.out.print("Phuong trinh co vo so nghiem");
        }
        else if (a == 0 && b != 0) {
            System.out.print("Phuong trinh vo nghiem");
        }
        else {
            double result = - b / a;
            System.out.print("Phuong trinh co nghiem x =" + result);
        }
    }
    
    public static void main(String args[]) throws IOException {
        System.out.print("Giai phuong trinh ax + b = 0\n");
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Nhap so a: ");
        double a = Double.parseDouble(br.readLine());
        
        System.out.print("Nhap so b: ");
        double b = Double.parseDouble(br.readLine());
        
        cal(a, b);
        
    }
}
