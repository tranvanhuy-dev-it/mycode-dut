import java.util.Scanner;
import java.util.HashSet;

public class docnhat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        HashSet<Integer> set = new HashSet<>();
        int l = 0; int r = 0;
        int sum = 0;
        while (r < n) {
            if (set.contains(a[r])) {
                set.remove(a[l]);
                l++;
            } else {
                set.add(a[r]);
                r++;
                sum += r - l + 1;
            }
        }

    }
}
