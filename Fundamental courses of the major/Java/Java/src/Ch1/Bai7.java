package Ch1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Bai7 {

    static boolean Namnhuan(int a) {
        if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)) return true;
        else return false;
    }
    
    static void Ngay(int month, int year) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||  month == 12) {
            System.out.print("Thang " + month + " Nam " + year + " co 31 ngay");
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            System.out.print("Thang " + month + " Nam " + year + " co 30 ngay");    
        }
        else if (month == 2) {
            if (Namnhuan(year)) {
                System.out.print("Thang " + month + " Nam " + year + " co 29 ngay");
            }
            else {
                System.out.print("Thang " + month + " Nam " + year + "co 28 ngay");
            }
        }
        else {
            System.out.print("Thang/nam khong hop le");    
        }
    }
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhap thang: ");
        int month = Integer.parseInt(br.readLine());
        System.out.print("Nhap nam: ");
        int year = Integer.parseInt(br.readLine());
        
        Ngay(month, year);
    }
}
