#include<stdio.h>
#include<math.h>


int main(){

    long long n, dem=1;
    scanf("%lld", &n);
    for(long long i=2; i<=n; i++){
        if(n%i==0){
            dem++;
        }
    }
    printf("%lld\n", dem);
    return 0;
}