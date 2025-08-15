#include<stdio.h>

void fibonaci(int n, int *fn){
    if (n==1 || n==2){
        *fn=1;
    }
    else if (n>2){
        int a=1, b=1, c;
        for (int i=2; i<n; i++){
            c=b;
            b=a+b;
            a=c;
        }
        *fn=b;
    }
}

int main(){

    int n, m, fn;
    scanf("%d%d", &n, &m);
    fibonaci(n, &fn);
    int thuong=fn%m;
    printf("%d\n", thuong);
    return 0;
}