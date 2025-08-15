#include<stdio.h>
int main(){
	int n;
	int s=0;
	printf("n=");
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		s=s+i*i;
	}
	printf("%d", s);
	return 0;
}
