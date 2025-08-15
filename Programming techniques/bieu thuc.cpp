#include<stdio.h>

int main(){
    
    int x;
    scanf("%d", &x);
    float fx = 2*x*x + +5*x + 9;
    float gx = -2*x*x + 4*x -9;
    if (x>=5){
        printf("%.f\n", fx);
    } 
    else printf("%.f\n", gx);
    return 0;
}