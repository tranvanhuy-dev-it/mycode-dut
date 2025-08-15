#include<stdio.h>

void sohoanhao(int n){
    for (int i=1; i<=n; i++){
        int s=0;
        for(int j=1; j<=i/2; j++){
            if(i%j==0){
                s+=j;
            }
        }
        if(s==i){
            printf("%d  ", i);
        }
    }
}
int main(){

    int n;
    scanf("%d", &n);
    sohoanhao(n);
    return 0;
}