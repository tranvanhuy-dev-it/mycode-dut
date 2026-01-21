#include<stdio.h>

int main(){
    
    int n, dem=0;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++){
       scanf("%d", &A[i]);
    }
    for (int i=0; i<n; i++){
        if (A[i]<2015 && A[i]&&2==0){
            dem=1;
            break;
        }
    }
    if(dem=1){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}