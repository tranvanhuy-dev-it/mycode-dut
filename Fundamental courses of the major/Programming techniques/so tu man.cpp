#include<stdio.h>
#include<math.h>


int main(){

    int N;
    scanf("%d", &N);
    int n=N, k=0;
    float a=N;
    while(N!=0){
        N=N/10;
        k++;
    }
    float s=0;
    while(n!=0){
        int du=n%10;
        n=n/10;
        s+=pow(du, k);
    }
    if(s==a){
        printf("YES\n");
    }
    else printf("NO\n");
    return 0;
}