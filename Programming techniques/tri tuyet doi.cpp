#include<stdio.h>

int main(){
    
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a<0){
        printf("%d ", -a);
    }
    else printf("%d ", a);
    if(b<0){
        printf("%d ", -b);
    }
    else printf("%d ", b);
    if(c<0){
        printf("%d ", -c);
    }
    else printf("%d ", c);
    return 0;
}