//bai toan xep hau
#include<stdio.h>

void Out(int n, int a[]){
    for(int i=1; i<=n; i++){
        printf("%-2d", a[i]);
    }
    printf("\n");
}

void xephau(int n, int i, int x[], int a[], int b[], int c[]){
    for (int j=1; j<=n; j++){
        if (a[j]==1 && b[i+j]==1 && c[i-j+n]==1){
            x[i]=j;
            a[j]=0;
            b[i+j]=0;
            c[i-j+n]=0;

            if(i==n){
                Out(n, x);
            }
            else{
                xephau(n, i+1, x, a, b, c);
                
            }
            a[j]=1;
            b[i+j]=1;
            c[i-j+n]=1;

        }
        
    }

}

int main(){
    int n, a[101], b[201], c[201], x[101];
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        a[i]=1;
    }
    for (int i=1; i<=n*2; i++){
        b[i]=1;
        c[i]=1;
    }
    xephau(n, 1, x, a, b, c);
    return 0;
}