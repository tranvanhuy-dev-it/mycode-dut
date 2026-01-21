#include<stdio.h>


int main(){
    
    unsigned int n, nhiphan;
    scanf("%u", &n);
    int a[100];
    int i=0;
    if (n==0){
    	printf("0");
	}
    else {
    	while(n!=0){
    	
    	nhiphan=n%2;
    	n=n/2;
    	a[i]=nhiphan;
    	i++;
	}
	
	for (int j=i-1; j>=0; j--){
		printf("%d", a[j]);
	}
	}
	
	return 0;
}
