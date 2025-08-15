#include<stdio.h>

int main(){
	
	long long n, k;
	scanf("%lld%lld", &n, &k);
	long long A[1000000];
	for(long long i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	long long bientg;
	for (long long i=0; i<n-1; i++){
		for (long long j=i+1; j<n; j++){
			if (A[i]>A[j]){
				bientg=A[i];
				A[i]=A[j];
				A[j]=bientg;
			}
		}
	}
	long long s=0;
	for (long long i=0; i<k; i++){
		s+=A[i];
	}
	printf("%lld", s);
	return 0;
}
