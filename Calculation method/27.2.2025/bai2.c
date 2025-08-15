#include <stdio.h>

void hoocnerTongQuat(int n, double a[], double c, double b[]){
    b[0]=a[0];
    for(int k=n; k>0; k--){
        for(int i=1; i<=k; i++){
            a[i]=a[i-1]*c+a[i];
        }
        b[k]=a[k];
    }
}
int main(){
    int n;
    printf("Nhap bac cua da thuc n: ");
    scanf("%d", &n);

    double a[n+1];
    printf("Nhap cac he so cua da thuc (tu bac %d den bac 0):\n", n);
    for (int i= 0; i<=n; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
    double c;
    printf("Nhap gia tri c: ");
    scanf("%lf", &c);

    double b[n+1];
    hoocnerTongQuat(n, a, c, b);

    printf("Da thuc p(y + c) co he so:\n");
    for (int i=0; i<=n; i++){
        printf("b[%d] = %.2lf\n", i, b[i]);
    }

    return 0;
}