#include<stdio.h>

int main(){

    int n ;
    float c, a[1000];
    int i, k;
    printf("Nhap vao bac cua da thuc: "); scanf("%d", &n);
    for(i=0; i<=n; i++){
        printf("Nhap vao he so a[%d]: ", i); scanf("%f", &a[i]);
    }
    printf("Nhap gia tri can tinh: "); scanf("%f", &c);
    for (k=n; k>=1; k--){
        for (i=1; i<=k; i++){
            a[i]=a[i-1]*c+a[i];
        }
        printf("%f ", a[i]);
    }

    return 0;
}