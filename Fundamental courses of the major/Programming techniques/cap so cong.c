#include<stdio.h>

void nhap(int n, int A[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
//1 2 3 4 5
int xuly(int n, int A[1000]){
    for (int i=0; i<n-2; i++){
        if (0.5*(A[i]+A[i+2])!=A[i+1]){
            return 0;
        }
    }
    return 1;
}
int main(){

    int n, A[1000];
    scanf("%d", &n);
    nhap(n, A);
    if (xuly(n, A)==1){
        printf("YES\n");
        printf("%d\n", A[1]-A[0]);
    }
    else{
        printf("NO\n");
    }
    return 0;
}