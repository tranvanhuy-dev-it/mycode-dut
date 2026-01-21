package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai4 {
    
    static void cal(double a, double b, double c, double d, double e, double f) {
        double D = a * e - b * d;
        double dx = c * e - b * f;
        double dy = a * f - d * c;
        
        if (D == 0 && (dx != 0 || dy != 0)) {
            System.out.print("He phuong trinh vo nghiem");
        }
        else if (D == 0 && dx == 0 && dy == 0) {
            System.out.print("He phuong trinh vo so nghiem");
        }
        else {
            double x = dx / D;
            double y = dy / D;
            System.out.print("Nghiem cua he phuong trinh la\nx = " + x + "\ny = " + y);
        }
    }

    public static void main(String args[]) throws IOException{
        System.out.print("Giai he phuong trinh\nax + by = c\ndx + ey = f\n");
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhap so a: ");
        double a = Double.parseDouble(br.readLine());
        System.out.print("Nhap so b: ");
        double b = Double.parseDouble(br.readLine());
        System.out.print("Nhap so c: ");
        double c = Double.parseDouble(br.readLine());
        System.out.print("Nhap so d: ");
        double d = Double.parseDouble(br.readLine());
        System.out.print("Nhap so e: ");
        double e = Double.parseDouble(br.readLine());
        System.out.print("Nhap so f: ");
        double f = Double.parseDouble(br.readLine());
        
        cal(a, b, c, d, e, f);
    }
}
