#include<stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);
	int A[n];
	A[1]=1;
	A[2]=1;
	printf("1 1 ");
	for (int i=3; i<=n; i++){
		A[i]=A[i-1]+A[i-2];
		printf("%d ", A[i]);
	}
	return 0;
}
