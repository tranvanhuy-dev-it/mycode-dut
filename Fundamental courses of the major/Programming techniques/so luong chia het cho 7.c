#include<stdio.h>

void nhap(int n, int A[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
int xuly(int n, int A[1000]){
    int dem=0;
    for (int i=0; i<n; i++){
        if(A[i]>0 && A[i]%7==0){
            dem++;
        }
    }
    return dem;
}
int main(){

    int n, A[1000];
    scanf("%d", &n);
    nhap(n, A);
    printf("%d\n", xuly(n, A));
    return 0;
}