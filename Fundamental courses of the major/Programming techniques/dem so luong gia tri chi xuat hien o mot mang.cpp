#include<stdio.h>

void nhapA(int n, int A[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}
void nhapB(int n, int B[1000]){
    for (int i=0; i<n; i++){
        scanf("%d", &B[i]);
    }
}
int xuly(int n, int A[1000], int B[1000]){
    int dem=0;
    for (int i=0; i<n; i++){
        int k=1;
        for (int j=0; j<n; j++){
            if (A[i]==B[j]){
                k=0;
                break;
            }
        }
        if (k==1){
            dem++;
        }
    }
    for (int i=0; i<n; i++){
        int k=1;
        for (int j=0; j<n; j++){
            if (B[i]==A[j]){
                k=0;
                break;
            }
        }
        if (k==1){
            dem++;
        }
    }
    return dem;
}
int main(){

    int n, A[1000], B[1000];
    scanf("%d", &n);
    nhapA(n, A);
    nhapB(n, B);
    int dem = xuly(n, A, B);
    printf("%d\n", dem);
    return 0;
}