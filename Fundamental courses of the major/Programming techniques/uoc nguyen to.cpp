#include<stdio.h>
#include<math.h>


int main(){

    int N, dem=1;
    scanf("%d", &N);
    for (int n=2; n<=N; n++){
       if (n==2){
          printf("2 ");
       }
        if (n>=3){
        for (int i=2; i<=sqrt(n); i++){
                if(n%i==0){
                    dem=0;
                    break;
                }
                dem=1;
            }
            if(dem==1){
                printf("%d ", n);
            }
        }

    }
return 0;
}