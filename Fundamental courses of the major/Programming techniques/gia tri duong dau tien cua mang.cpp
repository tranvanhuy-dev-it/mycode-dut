#include <stdio.h>

int kiemtra(int n, int A[]) {
    int check = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0) { 
            printf("%d\n", A[i]);
            check = 1; 
            break; 
        }
    }
    return check; 
}

int main() {
    int n, i;
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }  
    int x = kiemtra(n, A);
    if (x == -1) {
        printf("NO\n");
    }
    return 0;
}
