package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai17 {
    
    public static void sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            isPrime[i] = true;

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        System.out.println("Cac so nguyen to <= " + n + ":");
        for (int i = 2; i <= n; i++) {
            if (isPrime[i])
                System.out.print(i + " ");
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("San so nguyen to\nNhap n: ");
        int n = Integer.parseInt(br.readLine());
        sieve(n);
    }
}