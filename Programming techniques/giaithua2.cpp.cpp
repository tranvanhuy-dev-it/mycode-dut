#include<stdio.h>

int main(){
	
	int n;
	float s=0;
	float gt=1;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			gt=gt*j;
		}
		s=s+1.0/gt;
	}
	printf("%f", s);
	return 0;
}
