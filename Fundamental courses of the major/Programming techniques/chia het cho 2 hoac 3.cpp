#include<stdio.h>

void chiahet(int n, int *k){
    *k=0;
    for(long i=1; i<=n*n; i++){
        if(i%2==0 || i%3==0){
            (*k)++;
        }
    }
}

int main(){

    int n, k;
    scanf("%d", &n);
    chiahet(n, &k);
    printf("%d\n", k);
    return 0;
}