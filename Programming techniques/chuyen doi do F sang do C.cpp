#include<stdio.h>

int main(){
    
    for (int i=0; i<300; i++){
        printf("%3d    %.2f\n", i,  5*(i-32)*(1.0/9));
    }
    return 0;
}