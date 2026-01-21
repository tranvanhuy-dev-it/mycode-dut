#include<stdio.h>

int main(){
    int n, k;
    scanf("%d%d", &n, &k);  // Input n and k

    if (n < k) {  // Invalid case where n < k
        printf("Invalid input: n must be greater than or equal to k.\n");
        return 1;
    }

    float ngt = 1, nt1gt = 1, kgt = 1;

    // Calculating factorial of n
    for (int i = 1; i <= n; i++) {
        ngt *= i;
    }

    // Calculating factorial of k
    for (int i = 1; i <= k; i++) {
        kgt *= i;
    }

    // Calculating factorial of (n - k)
    for (int i = 1; i <= (n - k); i++) {
        nt1gt *= i;
    }

    // Calculating combination
    float tohop = (ngt / (kgt * nt1gt));

    // Output result
    printf("Combination (C(n, k)) = %.0f\n", tohop);

    return 0;
}
