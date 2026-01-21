#include<stdio.h>

int main(){
	
	int m, n, t;
	scanf("%d%d", &m, &n);
	int a=m;
	int b=n;
	if(n>m){
		t=m;
		m=n;
		n=t;
	}
	while(n!=0){
		t=n;
		n=m%n;
		m=t;	
	}
	printf("UCLN=%d\n", m);
	int BCNN;
	if(m==1){
	    printf("BCNN=%d\n", a*b);	
	}
	else {
		printf("BCNN=%d\n", (a*b)/m);
	}
	return 0;
}
