#include<stdio.h>

int n;
long long k;
int A[25];    
long long B[25];
int found = 0;

void out() {
    long long s = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            s += B[i];
        }
    }
    if (s == k) {
        found = 1;
    }
}

void Try(int i) {
    if (found) return;
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n - 1) out();
        else Try(i + 1);
    }
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &B[i]);
    }
    Try(0);

    if (found) printf("YES\n");
    else printf("NO\n");

    return 0;
}
