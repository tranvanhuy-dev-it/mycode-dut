#include<stdio.h>

int main(){

    char ch;
    scanf("%c", &ch);
    if(ch=='f' || ch=='F'){
        printf("Ban chon menu File\n");
    }
    if(ch=='h' || ch=='H'){
        printf("Ban chon menu Help\n");
    }
    return 0;
}