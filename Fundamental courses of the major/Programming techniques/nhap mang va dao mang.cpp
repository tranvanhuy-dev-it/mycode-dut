#include<stdio.h>

void nhap(int n, int A[100]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}

void dao(int A[100], int bientg, int n){
    for(int i=0; i<n/2; i++){
        bientg=A[i];
        A[i]=A[n-i-1];
        A[n-i-1]=bientg;
    }
}

void xuat(int n, int A[100]){
    for (int i=0; i<n; i++){
        printf("%3d", A[i]);
    }
}

int main(){

    int n, bientg, A[100];
    scanf("%d", &n);
    nhap(n, A);
    dao(A, bientg, n);
    xuat(n, A);
    return 0;
}