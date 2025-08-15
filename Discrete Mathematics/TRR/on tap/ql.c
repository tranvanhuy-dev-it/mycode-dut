#include <stdio.h>

char B[] = {'A', 'B', 'C'};
char X[100];
int n;

void out() {
    for (int i = 0; i < n; i++) {
        printf("%c", X[i]);
    }
    printf("\n");
}

void Try(int i) {
    for (int j = 0; j < 3; j++) { 
        if (i == 0 || B[j] != X[i - 1]) { 
            X[i] = B[j];
            if (i == n - 1) out();
            else Try(i + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    Try(0);
    return 0;
}
