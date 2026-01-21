#include <stdio.h>

void hoocnerTongQuat(int n, double a[], double c, double b[]){
    double d[n + 1];
    for (int i = 0; i <= n; i++){
        d[i] = a[i];
    }
    b[0]=d[0];
    for(int k=n; k>0; k--){
        for(int i=1; i<=k; i++){
            d[i]=d[i-1]*c+d[i];
        }
        b[k]=d[k];
    }
    printf("Da thuc p(y + %.lf) co he so:\n", c);
    for (int i=0; i<=n; i++){
        printf("b[%d] = %.1lf\n", i, b[i]);
    }
}
int main(){
    double a[6]={1, 0, 8, -2, 1, -1};
    double b[6];
    hoocnerTongQuat(5, a, 1, b);
    hoocnerTongQuat(5, a, 3, b);
    hoocnerTongQuat(5, a, -1, b);
    hoocnerTongQuat(5, a, -4, b);
    return 0;
}