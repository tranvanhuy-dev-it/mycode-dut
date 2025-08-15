#include <stdio.h>

char X[6] = {'a', 'b', 'c', 'd', 'e', 'f'}, A[6];
int B[6];

void out() {
    for (int i = 0; i < 6; i++) {
        printf("%c ", A[i]);
    }
    printf("\n");
}

void Try(int k) {
    for (int i = 0; i < 6; i++) {
        if (B[i] == 1) {
            B[i] = 0;
            A[k] = X[i];
            if (k == 5) out();
            else Try(k + 1);
             B[i] = 1;
        }
    }
}

int main() {
    for (int i = 0; i < 6; i++) {
        B[i] = 1;
    }
    Try(0);
    return 0;
}
