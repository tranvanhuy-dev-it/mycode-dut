package Day3;

public class KiemTraMEM {
	public static void main(String[] args) {
		System.out.println("Memory: " + Runtime.getRuntime().freeMemory());
		Info info[] = new Info[1000];
		for (int i = 0; i < 1000; i++) {
			info[i] = new Info(10000000);
			if (i % 100 == 0) {
				System.out.println("Memory: " + Runtime.getRuntime().freeMemory());
			}
		}
	}
}

class Info {
	int a[];
	public Info(int n) {
		a = new int[n];
	}
}