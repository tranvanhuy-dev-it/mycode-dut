#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct PolyInfo {
	unsigned int high_power;
	int coeff[MAX_SIZE + 1];
};

typedef struct PolyInfo *Polynomial;

Polynomial create() {
	Polynomial poly = (Polynomial)malloc(sizeof(struct PolyInfo));
	poly->high_power = 0;
	for (unsigned int i = 0;i <= MAX_SIZE; i++)
		poly->coeff[i] = 0;
	return poly;
}

unsigned int max(unsigned int a, unsigned int b) {
	return a>b?a:b;
}

Polynomial add(Polynomial A, Polynomial B) {
	Polynomial C = create();
	C->high_power = max(A->high_power, B->high_power);
	for (int i = 0; i <= C->high_power; i++)
		C->coeff[i] = A->coeff[i] + B->coeff[i];
	return C;
}

Polynomial mult(Polynomial A, Polynomial B){
	Polynomial C = create();
	C->high_power = A->high_power + B->high_power;
	int i, j;
	for (i = 0; i <= A->high_power; i++) {
		for (j = 0; j <= B->high_power; j++) {
			C->coeff[i + j] += A->coeff[i] * B->coeff[j];
		}
	}
	return C;
}
 
void show(Polynomial poly) {
	for (int i = poly->high_power; i >= 0; i--)
		printf("%dx^%u ", poly->coeff[i], i);
}

int main() {
	Polynomial A, B, C;
	A = create();
	B = create();
	
	int coeff_A[] = {1, -3 , 2, 0, 0, 1};
	int coeff_B[] = {-4, 0 , 3};
	
	int i;
	A->high_power = sizeof(coeff_A)/sizeof(coeff_A[0]) - 1;	
	
	for (i = 0; i <= A->high_power; i++)
		A->coeff[i] = coeff_A[i];			
	
	B->high_power = sizeof(coeff_B)/sizeof(coeff_B[0]) - 1;	
	for (i = 0; i <= B->high_power; i++)
		B->coeff[i] = coeff_B[i];
		
	printf("\nA = "); 
	show(A);

	printf("\nB = ");
	show(B);

	C = add(A, B);
	printf("\nA + B = ");
	show(C);

	C = mult(A, B);
	printf("\nA x B = ");
	show(C);
	printf(C);
	return 0;
}