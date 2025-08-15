//liet ke tap con
#include<stdio.h>

void Out(int n, int a[]);
void Try(int n, int i, int x[]) {
    if(i>n){
        Out(n, x);
        return;
    }
    x[i]=1;
    Try(n, i+1, x);
    x[i]=0;
    Try(n, i+1, x);
   
} 

int main() {
    int n, x[1001]={0};
    scanf("%d", &n);
    Try(n, 1, x);
    return 0;
}

void Out(int n, int a[]) {
    for (int i=1; i<=n; i++){
        if(a[i]) printf("%d", i);
    }
    printf("\n");
}