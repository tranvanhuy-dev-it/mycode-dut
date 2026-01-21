#include<stdio.h>

int main (){

    for (int i=1; i<=100; i++){
        if (i%2!=0){
            if (i==5 || i==7 || i==93){
                continue;
            }
            printf("%d  ", i);
        }
    }
    return 0;
}