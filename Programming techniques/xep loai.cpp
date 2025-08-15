#include<stdio.h>

int main(){
	float a, b, c;
	scanf("%f%f%f", &a, &b, &c);
	float t=0.2*(a+b)+0.6*c;
	if (t>=8.5&&t<=10.0){
		printf("A");
	}
	if (t<8.5&&t>=7.0){
		printf("B");
	}
	if (t>=5.5&&t<7.0){
		printf("C");
	}
	if (t<5.5&&t>=4.0){
		printf("D");
	}
	if (t<4.0){
		printf("F");
	}
	return 0;
}
