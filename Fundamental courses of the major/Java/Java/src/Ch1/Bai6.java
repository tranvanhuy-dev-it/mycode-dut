package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai6 {

    static int Karaoke(int a, int b) {
        if (a >= 18) return 60000*(b - a);
        else if (b < 18) return 45000*(b - a);
        else return 45000*(18 - a) + 60000*(b - 18 + 1);
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhap gio bat dau: ");
        int a = Integer.parseInt(br.readLine());
        System.out.print("Nhap gio key thuc: ");
        int b = Integer.parseInt(br.readLine());
        
        int Total = Karaoke(a, b);
        System.out.print("Tong so tien la: " + Total);
    }
}
