#include<stdio.h>

int xuly(int n){
    if (n==1 || n==2){
            return 1;
    }
    else{
        int a=1, b=1;
        for (int i=2; i<n; i++){
            int c=b;
            b=a+b;
            a=c;
        }
            return b;
    }
}
int main(){

    int n;
    scanf("%d", &n);
    printf("%d\n", xuly(n));
    return 0;
}