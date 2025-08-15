#include<stdio.h>

int main(){
	
	float p1=3, p2=3, a[7]={3, 0, 0, 8, -2, 1, -5};
	int i;
	for (i=0; i<6; i++){
		p1=p1*-2+a[i+1];
		p2=p2*-3+a[i+1];
	}
	printf("p(-2)=%.2f\n", p1);
	printf("p(-3)=%.2f\n", p2);
	
	return 0;
}