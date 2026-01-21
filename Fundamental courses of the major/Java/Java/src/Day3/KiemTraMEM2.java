package Day3;

public class KiemTraMEM2 {
	
	static void abc() {
		int a[] = new int[1000];
		System.out.println("Memory: " + Runtime.getRuntime().freeMemory());
		abc();	
	}
	
	public static void main(String[] args) {
		abc();        							
	}
}

//Runtime.getRuntime().gc(); gom rac do java