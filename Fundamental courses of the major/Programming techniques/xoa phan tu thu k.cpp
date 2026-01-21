#include<stdio.h>

void nhap(int n, int A[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
// 1 2 3 4 5(k=4) 6 7 8     k=5
void xuly(int n, int k, int A[1000]){
    for (int i=k-1; i<n-1; i++){
        A[i]=A[i+1];
    }
}
void xuat(int n, int A[1000]){
    for (int i=0; i<n; i++){
        printf("%-2d", A[i]);
    }
    printf("\n");
}
int main(){

    int n, k, A[1000];
    scanf("%d%d", &n, &k);
    nhap(n, A);
    xuly(n, k, A);
    n=n-1;
    xuat(n, A);
    return 0;
}