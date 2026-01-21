#include<stdio.h>

int main(){
	
	int n;
	printf("n=");
	scanf("%d", &n);
	long gt=1;
	if (n%2==0){
		for (int i=2; i<=n; i+=2){
			gt=gt*i;
		}
	}
	else {
		for (int i=1; i<=n; i+=2){
			gt=gt*i;
		}
	}
	printf ("giai thua= %d", gt);
	return 0;
}
