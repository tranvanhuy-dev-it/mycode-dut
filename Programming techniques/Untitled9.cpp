#include<stdio.h>

int main(){
	
	int n, t=3;
	scanf("%d", &n);
	int a=1, b=1, c;
	if (n==1) printf("%d ", a);
	if (n==2) printf("%d %d ", a, b);
	if(n>3){
		printf("%d %d ", a, b);
		while(t<=n){
			c=b;
			b=a+b;
			a=c;
			printf("%d ", b);
			t++;
		}
	}
	return 0;
}
