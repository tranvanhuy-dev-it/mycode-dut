package bkdnojday1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class bai3 {
	
    public static void main(String[] args) throws IOException{
    	
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    	StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        long S = Long.parseLong(st.nextToken());

        int[] a = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int i = 0;
        long sum = 0;
        int res = Integer.MAX_VALUE;

        for (int j = 0; j < N; j++) {
            sum += a[j];
            while (sum >= S) {
            	int newm = j - i + 1;
            	if (newm < res) res = newm;
                sum -= a[i];
                i++;
            }
        }

        if (res == Integer.MAX_VALUE) {
        	System.out.println(0);
        } else {
        	System.out.println(res);
        }
    }
}
