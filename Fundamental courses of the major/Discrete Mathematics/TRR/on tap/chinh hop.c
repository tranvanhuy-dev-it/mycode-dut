#include <stdio.h>

int n, k;
int X[10];
int used[10];

void out() {
    for (int i = 0; i < k; i++) {
        printf("%d ", X[i]);
    }
    printf("\n");
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            X[i] = j;
            used[j] = 1;
            if (i == k - 1) out();
            else Try(i + 1);
            used[j] = 0;
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    Try(0);
    return 0;
}
