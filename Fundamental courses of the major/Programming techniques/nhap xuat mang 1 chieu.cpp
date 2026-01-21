#include<stdio.h>

void nhap(int n, int A[100]){
    for (int i=0; i<n; i++){
        printf("A[%d]=", i);
        scanf("%d", &A[i]);
    }
}

void xuat(int n, int A[100]){
    for (int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
}

int main(){

    int n, A[100];
    scanf("%d", &n);
    nhap(n, A);
    xuat(n, A);
    return 0;
}