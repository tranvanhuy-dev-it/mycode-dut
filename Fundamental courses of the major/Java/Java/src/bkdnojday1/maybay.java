package bkdnojday1;

import java.util.*;
import java.io.*;

public class maybay {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); 
        int[] hang = new int[N]; 
        int maxHang = 0;
        for (int i = 0; i < N; i++) {
            hang[i] = sc.nextInt();
            if (hang[i] > maxHang) maxHang = hang[i];
        }

        int[] thoiDiemHang = new int[maxHang + 1]; 

        int thoiGian = 0; 

        for (int i = 0; i < N; i++) {
            int khach = i;
            int denHang = hang[i]; 
            int di = 0; 

            for (int j = 1; j <= denHang; j++) {
                di = Math.max(di + 1, thoiDiemHang[j] + 1);
                thoiDiemHang[j] = di; 
            }

            thoiDiemHang[denHang] = di + 5 - 1;

            if (thoiDiemHang[denHang] > thoiGian) {
                thoiGian = thoiDiemHang[denHang];
            }
        }

        System.out.print(thoiGian);
    }
}
