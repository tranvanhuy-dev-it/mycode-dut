#include<stdio.h>
#include<math.h>


int main(){

    int a, dem=0;
    do{
        scanf("%d", &a);
        if(a%2!=0){
            dem++;
        }
        
    }
    while(a!=0);
    printf("%d\n", dem);
    return 0;
}