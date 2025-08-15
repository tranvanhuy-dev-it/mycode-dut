#include<stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    int max=A[0];
    int vitri=0;
    for (int i=1; i<n; i++){
        if(A[i]>=max){
            max=A[i];
            vitri=i;
        }
    }
    printf("%d\n", vitri);
    return 0;
}