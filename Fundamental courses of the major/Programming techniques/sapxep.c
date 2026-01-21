#include<stdio.h>

void nhap(int n, int A[]);
void xuat(int n, int A[]);
void quicksort(int A[], int l, int r){
    int p=A[(l+r)/2];
    int i=l, j=r;
    while(i<j){
        while(A[i]<p){
            i++;
        }
        while(A[j]>p){
            j--;
        }
        if(i<=j){
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i++;
            j--;
        }
    }
    if(l<j){
        quicksort(A, l, j);
    }
    if(i<r){
        quicksort(A, i, r);
    }
}
int main(){
    int n, A[100001];
    scanf("%d", &n);
    nhap(n, A);
    printf("Mang truoc khi sap xep: ");
    xuat(n, A);
    quicksort(A, 0, n-1);
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
    for (int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}