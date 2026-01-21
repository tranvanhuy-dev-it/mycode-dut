package Ch1;

import java.util.Scanner;

public class Bai20 {

    public static int fibonacciPosition(int n) {
        if (n < 0) return -1;

        int f0 = 0;
        int f1 = 1;

        if (n == 0) return 0;
        if (n == 1) return 1;

        int pos = 2;
        while (true) {
            int f = f0 + f1;
            if (f == n) return pos;
            if (f > n) return -1;

            f0 = f1;
            f1 = f;
            pos++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Nhap n: ");
        int n = sc.nextInt();

        int pos = fibonacciPosition(n);

        if (pos != -1)
            System.out.println(n + " thuoc day Fibonacci, o vi tri: " + pos);
        else
            System.out.println(n + " khong thuoc day Fibonacci");
    }
}