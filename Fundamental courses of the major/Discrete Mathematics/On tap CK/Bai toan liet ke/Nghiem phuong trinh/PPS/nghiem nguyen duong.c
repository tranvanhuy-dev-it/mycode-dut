#include <stdio.h>

int n, k, A[101], p = 0;
int stop = 0;

void out() {
    p++;
    printf("Nghiem thu %-3d:", p);
    for (int i = 1; i <= n; i++) {
        printf(" x%d = %d,  ", i, A[i]);
    }
    printf("\n");
}

void init() {
    for (int i = 1; i <= n; i++) A[i] = 1;
    A[n] = k - (n - 1);  // đảm bảo tổng ban đầu đúng k
    stop = 0;
}

void gen() {
    int i = n - 1;
    while (i >= 1 && A[i] == k - (n - 1)) i--;

    if (i == 0) {
        stop = 1;
    } else {
        A[i]++;
        int sum = 0;
        for (int j = 1; j <= i; j++) sum += A[j];

        int remain = k - sum;
        int t = n - i;

        if (remain < t) {
            stop = 1;
            return;
        }

        for (int j = i + 1; j < n; j++) {
            A[j] = 1;
            remain--;
        }
        A[n] = remain;
    }
}

void method() {
    if (k < n) {
        printf("Khong co nghiem nguyen duong nao!\n");
        return;
    }

    init();
    out();
    while (!stop) {
        gen();
        if (!stop) out();
    }
}

int main() {
    printf("Nhap n va k (k >= n): ");
    scanf("%d%d", &n, &k);
    method();
    printf("\nTong so nghiem nguyen duong: %d\n", p);
    return 0;
}
