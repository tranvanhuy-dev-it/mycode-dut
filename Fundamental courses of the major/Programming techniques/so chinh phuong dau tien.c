#include<stdio.h>
#include<math.h>

int nhap(int n, int A[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
int xuly(int n, int A[1000]){
    for (int i=0; i<n; i++){
        int a=sqrt(A[i]);
        if (a*a==A[i]){
            return A[i];
        }
    }
}
int main(){

    int A[1000];
    int n;
    scanf("%d", &n);
    nhap(n, A);
    printf("%d\n", xuly(n, A));
    return 0;
}