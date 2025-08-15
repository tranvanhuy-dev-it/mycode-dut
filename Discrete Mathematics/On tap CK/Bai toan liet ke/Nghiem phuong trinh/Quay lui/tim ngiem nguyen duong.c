#include<stdio.h>
int k, n, A[101], p = 0;

void out(){
    printf("Nghiem thu %-3d:", p);
    for (int i = 1; i <= n; i++) {
        printf(" x%d = %d,  ", i, A[i]);
    }
    printf("\n");
}

void Try(int i, int s) {
    for (int j = 1; j <= k + n - 1; j++) {
        A[i] = j;
        if (i == n) {
            if (s + j == k) {
                p++;
                out();
            }
        }
        else Try(i + 1, s + j);
    }
}
int main() {

    scanf("%d%d", &n, &k);
    Try(1, 0);
    return 0;
}
