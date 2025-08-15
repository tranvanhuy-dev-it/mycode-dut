#include<stdio.h>

int main(){


    int m, n;
    scanf("%d%d", &m, &n);
    int A[m][n];
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            printf("A[%d][%d]=", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            printf("%d ", &A[i][j]);
        }
        printf("\n");
    }
    return 0;
}