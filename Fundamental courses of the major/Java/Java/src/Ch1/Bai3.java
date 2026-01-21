package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai3 {

    static void cal(double a, double b, double c) {
        double delta = b*b - 4*a*c;
        if (delta < 0) {
            System.out.print("Phuong trinh vo nghiem");
        }
        else if (delta == 0) {
            double x = - b / (2 * a);
            System.out.print("Phuong trinh co 1 nghiem x = " + x);
        }
        else {
            double x1 = (- b + Math.sqrt(delta) / (2 * a));
            double x2 = (- b - Math.sqrt(delta) / (2 * a));
            System.out.print("Phuong trinh co 2 nghiem\nx1 = " + x1 + "\nx2 = " + x2);
        }
    }
    
    public static void main(String args[]) throws IOException {
        System.out.print("Giai phuong trinh ax^2 + bx + c = 0\n");
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Nhap so a: ");
        double a = Double.parseDouble(br.readLine());
        
        System.out.print("Nhap so b: ");
        double b = Double.parseDouble(br.readLine());
        
        System.out.print("Nhap so c: ");
        double c = Double.parseDouble(br.readLine());
        
        cal(a, b, c);
    }
}
