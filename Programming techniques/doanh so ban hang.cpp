#include<stdio.h>

int main(){

    int totalSale;
    printf("totalSale: ");
    scanf("%d", &totalSale);
    int hh;
    float hoahong;
    if (totalSale<=100) float hoahong=(totalSale*0.05);
    if (totalSale>100&&totalSale<=300) float hoahong=(totalSale*0.10);
    if (totalSale>300) float hoahong=(totalSale*0.20);
    printf("Hoa hong: %0.2f\n", hoahong);
    return 0;
}