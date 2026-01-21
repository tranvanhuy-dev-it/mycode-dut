//x3 >= 5
//x4 >= 6
#include<stdio.h>
int n, k, A[1001], p = 0, s = 0;
void Try(int i, int s) {
    int minj = 1;
    if (i == 3) minj = 5;
    if (i == 4) minj = 6;
    for (int j = minj; j <= n - s - (k - i); j++) {
        A[i] = j;
        if (i == k) {
            if (s + j == n) {
                p++;
                printf("Nghiem %-3d: ", p);
                for (int q = 1; q <= k; q++) {
                    printf("x%d = %d, ", q, A[q]);
                }
                printf("\n");
            }
        }
        else Try(i + 1, s + j);
    }
}
int main() {

    scanf("%d%d", &k, &n);
    Try(1, 0);
    return 0;
}