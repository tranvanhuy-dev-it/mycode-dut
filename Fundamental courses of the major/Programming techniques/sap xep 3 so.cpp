#include<stdio.h>

int main(){
	long long a, b, c;//1 1 2
	scanf("%lld %lld %lld", &a, &b, &c);
	long long max=a;
	if(b>max) max=b;
	if(c>max) max=c;
	long long min=a;
	if(b<min) min=b;
	if(c<min) min=c;
	long long d=a+b+c-max-min;
	printf("%lld %lld %lld", min, d, max);
	
	
 
	return 0;
}
