#include<stdio.h>
#include<string.h>

int main(){

    char A[100];                            //chuõi nhập vào
    char B[100];                            //chuỗi đảo  ngược
    printf("Nhap vao chuoi: ");
    fgets(A, sizeof(A), stdin);             //lệnh nhập vào chuỗi
    int l = strlen(A); 
    if (A[l - 1] == '\n') {
        A[l - 1] = '\0';
        l--;
    }                     
    for (int i=0; i<l; i++){                //đảo ngược chuỗi
        B[l-i-1]=A[i];
    }
    B[l]='\0';                              //kết thúc chuỗi đảo ngược
    int danhdau = 1;
    for (int i=0; i<l; i++){
        if (A[i]!=B[i]){
            danhdau = 0;
            break;                          //kiểm tra hai chuỗi
        }
    }
    if (danhdau){                           //in ra kết quả
      printf("Day nay la day palindrome!\n");
    }
    else printf("Day nay khong la day palindrome!\n");
    return 0;
}