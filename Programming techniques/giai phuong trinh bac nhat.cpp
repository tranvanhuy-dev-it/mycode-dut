#include<stdio.h>

int main(){

    int a, b;
    scanf("%d%d", &a, &b);
    if(a!=0 && b!=0){
        float k=-b*(1.0/a);
        printf("Phuong trinh co nghiem la: %.2f\n", k);
    }
    if (b==0){
        printf("Phuong trinh vo so nghiem!\n");
    }
    if (a==0 && b!=0){
        printf("Phuong trinh vo nghiem!\n");
    }
    return 0;
}