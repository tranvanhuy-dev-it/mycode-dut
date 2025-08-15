#include<stdio.h>

int main(){

    printf("                                                      BANG CUU CHUONG\n");
    for (int i=1; i<=10; i++){
        for (int j=2; j<=9; j++){
            printf("%d x %2d = %2d     ", j, i, i*j);
        }
        printf("\n");
    }
    return 0;
}
