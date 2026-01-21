#include<stdio.h>
#include<math.h>

void nhap(int n, int A[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
int xuly(int n, int A[1000]){
   while(n > 1)
    {
        if(n % 2 != 0)   
            return 0;
        n /= 2;
    }
    return 1;
}
int main(){

    int n, A[1000];
    scanf("%d", &n);
    nahp(n, A);
    
    return 0;
}