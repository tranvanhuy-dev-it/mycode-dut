#include<stdio.h>

void Out(int n, int a[]){
    for (int i=1; i<=n; i++){
        if(a[i]) printf("%-2d", i);
    }
    printf("\n");
}

void Try(int i, int n, int a[]){
    if(i>n){
        Out(n, a);
        return;
    }
    a[i]=1;
    Try(i+1, n, a);
    a[i]=0;
    Try(i+1, n, a);
}
int main(){
    int n, a[101]={0};
    scanf("%d", &n);
    Try(1, n, a);
    return 0;
}