#include<stdio.h>

void nhap(int m, int n, int A[1000][1000]){
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}
void xuat(int m, int n, int A[1000][1000]){
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
int max(int m, int n, int A[1000][1000]) {
    int s=0;
    for (int i=0; i<m; i++) {
        int max=A[i][0];
        for (int j=1; j<n; j++) {
            if (A[i][j]>max) {
                max=A[i][j];
            }
        }
        s+=max; 
    }
    return s;
}

int main() {
    int m, n;
    int A[1000][1000];
    scanf("%d%d", &m, &n);
    nhap(m, n, A);
    xuat(m, n, A);
    printf("%d\n", max(m, n, A));
    return 0;
}