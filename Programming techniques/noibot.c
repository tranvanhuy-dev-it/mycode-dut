#include<stdio.h>

void nhap(int n, int A[]);
void xuat(int n ,int A[]);
void noibot(int n, int A[]);
void hoandoi(int *x, int *y);
int main(){
    int n, A[100001];
    scanf("%d", &n);
    nhap(n, A);
    printf("Mang truoc khi sap xep: ");
    xuat(n, A);
    noibot(n, A);
    printf("Mang sau khi sap xep: ");
    xuat(n, A);
    return 0;
}
void nhap(int n, int A[]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
void xuat(int n, int A[]){
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
void hoandoi(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void noibot(int n, int A[]){
    for (int i=0; i<n-1; i++){
        for (int j=i; j<n; j++){
            if(A[i]>A[j]){
                hoandoi(&A[i], &A[j]);
            }
        }
    }
}