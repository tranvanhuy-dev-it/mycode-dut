#include <stdio.h>

void init(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        A[i] = 0;
    }
}

int islast(int n, int A[]) {
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) return 1;
    }
    return 0;
}

void gen(int n, int A[]) {
    int i = n;
    while (A[i] == 1) {
        A[i] = 0;
        i--;
    }
    A[i] = 1;
}

void print_perm(char subset[], int used[], char res[], int k, int i) {
    for (int j = 0; j < k; j++) {
        if (used[j] == 0) {
            res[i] = subset[j];
            used[j] = 1;
            if (i == k - 1) {
                for (int p = 0; p < k; p++) printf("%c ", res[p]);
                printf("\n");
            } else {
                print_perm(subset, used, res, k, i + 1);
            }
            used[j] = 0;
        }
    }
}

void method(int n, int A[], char B[], int k) {
    init(n, A);
    int stop = 1;

    while (stop) {
        int count = 0;
        char subset[100];
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) {
                subset[count++] = B[i - 1];
            }
        }

        if (count == k) {
            int used[100] = {0};
            char res[100];
            print_perm(subset, used, res, k, 0);
        }

        gen(n, A);
        stop = islast(n, A);
    }
}

int main() {
    int n = 5, k;
    int A[101];
    char B[100] = {'a', 'b', 'c', 'd', 'e'};
    scanf("%d", &k);
    method(n, A, B, k);
    return 0;
}
