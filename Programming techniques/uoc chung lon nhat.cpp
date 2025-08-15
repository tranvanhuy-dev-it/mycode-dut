#include<stdio.h>

int main(){
	
	unsigned long long a, b, c;
	scanf("%llu%llu", &a, &b);
     unsigned long long A=a;
    unsigned long long B=b;
    if(a>b){
        c=a;
        a=b;
        b=c;
    }
    while (b!=0){
        unsigned long long x=b;
        b=a%b;
        a=x;
    }
    unsigned long long bcnn=(A*B)/a;
    printf("%llu\n", bcnn);
	
	return 0;
}
