#include<stdio.h>
//nhap ma tran thu nhat
void matrix1(int m, int n, int A[][50]){
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            printf("A[%d][%d]=", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}
//nhap ma tran thu hai
void matrix2(int n, int p, int B[][50]){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=p; j++){
            printf("A[%d][%d]=", i, j);
            scanf("%d", &B[i][j]);
        }
    }
}
//nham hai ma tran
void tinh(int m, int n, int p, int A[][50], int B[][50]){
    for (int i=1; i<=m; i++){
        for (int k=1; k<=p; k++){
            int s=0;
            for (int j=1; j<=n; j++){
                s+=A[i][j]*B[j][k];
            }
            printf("%d ", s);
        }
        printf("\n\n");
    }
}

int main(){
    
    int m, n, p, A[50][50], B[50][50];
    scanf("%d%d%d", &m, &n, &p);
    matrix1(m, n, A);
    matrix2(n, p, B);
    tinh(m, n, p, A, B);
    return 0;
}