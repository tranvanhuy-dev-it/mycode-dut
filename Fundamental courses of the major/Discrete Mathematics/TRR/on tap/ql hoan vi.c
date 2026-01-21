#include<stdio.h>

void out(int n, int A[]) {
    int p = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) {
                if(i == 1) printf("a");
                if(i == 2) printf("b");
                if(i == 3) printf("c");
                if(i == 4) printf("d");
                if(i == 5) printf("e");
                if(i == 6) printf("f");
                p = 1;
            }
        }
}

void Try(int n, int A[], int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n) out(n, A);
        else Try(n, A, i + 1);
    }
}

int main() {

    int A[101];
    Try(6, A, 1);
    return 0;
}