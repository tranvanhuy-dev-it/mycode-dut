#include<stdio.h>

int main(){

    int start, end;
    scanf("%d %d", &start, &end);
    int k=0;
    for (int i=start; i<=end; i++){
        if (i%13==0){
            k=1;
            break;
        }
    }
    if (k==1){
        for (int i=start; i<=end; i++){
        if (i%13==0){
            printf("%d ", i);
        }
    }
    }
    if (k==0) printf("NO!\n");

    return 0;
}