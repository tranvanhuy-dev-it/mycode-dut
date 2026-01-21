#include <stdio.h>

char X[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
int A[6];

void out() {
    int count = 0;
    for (int i = 0; i < 6; i++)
        if (A[i] == 1) count++;
    printf("{ ");
    int p = 0;
    for (int i = 0; i < 6; i++) {
        if (A[i] == 1) {
            printf("%c", X[i]);
            p++;
            if (p < count) printf(", ");
        }
    }
    printf(" }\n");
}


void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == 6) out();
        else Try(i + 1);
    }
}
int main() {
    Try(0);
    return 0;
}
