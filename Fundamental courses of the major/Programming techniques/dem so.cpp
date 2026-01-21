#include<stdio.h>

int main(){
	long long n, k;
	k=0;
	scanf("%lld", &n);
	for (long long i=n; i<=n*n; i++){
		k=k+1;
	}
    printf("%lld", k);
	return 0;
}
