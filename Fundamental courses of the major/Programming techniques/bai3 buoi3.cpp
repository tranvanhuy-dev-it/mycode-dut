#include<stdio.h>

int main(){
	
	int n;
	int s=0;
	do{
	    scanf("%d", &n);
	    if(n!=-1) s=s+n;
	}
	while(n!=-1);
	printf("%d", s);
	return 0;
}
