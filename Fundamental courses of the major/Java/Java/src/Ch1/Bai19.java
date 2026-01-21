package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai19 {

    static void Fibo(int n) {
        if (n <= 0) System.out.print("Vui long nhap so duong");
        else if (n == 1) System.out.print("0");
        else if (n == 2) System.out.print("0 1 ");
        else {
            System.out.print("0 1 ");
            int a = 0, b = 1;
            for (int i = 3; i <= n; i++) {
                int temp = a + b;
                a = b;
                b = temp;
                System.out.print(b + " ");
            }
        }
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Day Fibonacci\nNhap n: ");
        int n = Integer.parseInt(br.readLine());
        
        Fibo(n);
    }
}
