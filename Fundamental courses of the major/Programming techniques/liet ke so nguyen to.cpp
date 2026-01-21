#include<stdio.h>

int i, n;
void nguyento(int i){
    int dem=1;
        for (int j=2; j<=i/2; j++){
            if(i%j==0){
                dem=0;
                break;
            }
        }
        if (dem==1){
            printf("%d ", i);
        }
    }
int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        nguyento(i);
    }
    return 0;
}