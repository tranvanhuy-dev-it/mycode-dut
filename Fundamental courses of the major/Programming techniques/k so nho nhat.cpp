#include<stdio.h>

void nhap(int n, int A[100]){
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
void hoandoi(int *x, int *y){
    int bientg;
    bientg=*x;
    *x=*y;
    *y=bientg;
}
void sapxep(int A[100], int n){
    for(int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(A[i]>A[j]){
                hoandoi(&A[i], &A[j]);
            }
        }
    }
}
int main(){
    int n, k, A[100], s=0;
    scanf("%d%d", &n, &k);
    nhap(n, A);
    sapxep(A, n);
    for(int i=0; i<k; i++){
    	s+=A[i];
	}
    return 0;
}
