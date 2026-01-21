package Ch1;

public class Bai18 {

    static boolean IsOk(int n) {
        int sum = 0;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        return sum == n;
    }
    
    static void Cal() {
        for (int i = 1; i <= 1000; i++) {
            if (IsOk(i)) {
                System.out.print(i + " ");
            }
        }
    }
    
    public static void main(String args[]) {
        System.out.print("So hoan hao nho hon 1000 la: ");
        Cal();
    }
}
