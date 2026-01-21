#include<stdio.h>

int main(){

    printf("Nhap va kich thuoc cua hai tam giac: ");
    int a;
    scanf("%d", &a);

    for (int i=0; i<a; i++){
        for (int j=0; j<a-i-2; i++){
            printf("=");
        }
        for (int k=0; k<i+1; k++){
            printf("+");
        }
        printf("\n");
    }
    return 0;
}