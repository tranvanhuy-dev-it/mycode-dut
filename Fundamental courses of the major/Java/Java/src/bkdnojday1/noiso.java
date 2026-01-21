package bkdnojday1;

import java.util.*;

public class noiso {

	static int dodai(int x) {
        if (x == 0) return 1;
        return (int) Math.log10(x) + 1;
    }

    static int ghduoi(ArrayList<Integer> arr, long value) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (arr.get(m) >= value) r = m;
            else l = m + 1;
        }
        return l;
    }

    static int ghtren(ArrayList<Integer> arr, long value) {
        int l = 0, r = arr.size();
        while (l< r) {
            int m = (l + r) / 2;
            if (arr.get(m) > value) r = m;
            else l = m+ 1;
        }
        return l;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            long l = sc.nextLong();
            long r = sc.nextLong();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            
            ArrayList<Integer>[] nhom = new ArrayList[11];
            for (int i = 0; i <= 10; i++) {
                nhom[i] = new ArrayList<>();
            }
            for (int x : a) {
                int d = dodai(x);
                nhom[d].add(x);
            }
            for (int i = 1; i <= 10; i++) {
                Collections.sort(nhom[i]);
            }
            
            long count = 0;
            for (int x : a) {
                for (int d = 1; d <= 10; d++) {
                    if (nhom[d].isEmpty()) continue;
                    long base = x * (long) Math.pow(10, d);
                    long minY = l - base;
                    long maxY = r - base;
                    if (minY > maxY) continue;
                    int left = ghduoi(nhom[d], minY);
                    int right = ghtren(nhom[d], maxY);
                    count += (right - left);
                }
            }
            System.out.println(count);
        }
    }
}