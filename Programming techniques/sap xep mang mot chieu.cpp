#include<stdio.h>

void nhap(int n, int A[100]){
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}

void xuat(int n, int A[100]){
    for(int i=0; i<n; i++){
        printf("%3d", A[i]);
    }
    printf("\n");
}

void hoandoi(int *x, int *y){
    float bientg;
    bientg=*x;
    *x=*y;
    *y=bientg;
}
void sapxep(int A[100], int n){
    for(int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(A[i]>A[j]){
                hoandoi(&A[i], &A[j]);
            }
        }
    }
}
int main(){
    int n, A[100];
    scanf("%d", &n);
    nhap(n, A);
    sapxep(A, n);
    xuat(n, A);
    return 0;
}