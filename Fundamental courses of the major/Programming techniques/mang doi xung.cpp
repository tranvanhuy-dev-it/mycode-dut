#include<stdio.h>

int main(){
    
    int n;
    int A[1000];
    printf("Nhap vao n: ");
    scanf("%d", &n);
    printf("Nhap vao mang:");
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    int B[n];
    for (int i=0; i<n; i++){
        B[n-i-1]=A[i];
    }
    int thu=1;
    for (int i=0; i<n; i++){
        if (A[i]!=B[i]){
            thu=0;
        }
    }
    if (thu){
        printf("YES\n");
    }
    else printf("NO\n");
    return 0;
}