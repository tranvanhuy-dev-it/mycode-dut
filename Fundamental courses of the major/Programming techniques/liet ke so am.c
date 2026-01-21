#include<stdio.h>

void nhap(int n, int A[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
void xuat(int n, int A[1000]){
    for (int i=0; i<n; i++){
        if (A[i]<0){
            printf("%d\n", A[i]);
        }
    }
}
int main(){
    int n, A[1000];
    scanf("%d", &n);
    nhap(n, A);
    xuat(n, A);
    return 0;
}