#include<stdio.h>
#include<math.h>

void nhap(int n, int A[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
void xuly(int n, int A[1000]){
    for (int i=0; i<n-1; i++){
        if (A[i]>abs(A[i+1])){
            printf("%2d", A[i]);
        }
    }
    printf("\n");
}
int main(){

    int n, A[1000];
    scanf("%d", &n);
    nhap(n, A);
    xuly(n, A);
    return 0;
}