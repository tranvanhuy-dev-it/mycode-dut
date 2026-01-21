#include<stdio.h>

int nt(int i){
    for (int j=2; j<=i/2; j++){
        if(i%j==0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
       if(nt(i)){
        printf("%d ", i);
       }
    }
    return 0;
}