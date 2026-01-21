#include <stdio.h>

void Init(int b[], int n);
void Out(int b[], int n);
int IsLast(int b[], int n);
void Gen(int b[], int n);
void Method(int b[], int n);

int main() {
    int n, b[100];
    scanf("%d", &n);
    Method(b, n);
    return 0;
}

void Init(int b[], int n) {
    for (int i = 0; i < n; i++) {  
        scanf("%d", &b[i]);
    }
}

void Out(int b[], int n) {
    for (int i = 0; i < n; i++) {  
        printf("%d ", b[i]);
    }
    printf("\n");
}

int IsLast(int b[], int n) {
    for (int i = 0; i < n - 1; i++) {  
        if (b[i] < b[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void Gen(int b[], int n) {
    int i = n - 2;  
    while (i >= 0 && b[i] >= b[i + 1]) {  
        i--;  
    }

    if (i >= 0) {  
        int j = n - 1;
        while (b[j] <= b[i]) {  
            j--;
        }

        int t = b[i];
        b[i] = b[j];
        b[j] = t;
    }

    int l = i + 1, r = n - 1;
    while (l < r) {
        int t = b[l];
        b[l] = b[r];
        b[r] = t;
        l++;
        r--;
    }
}

void Method(int b[], int n) {
    Init(b, n);
    do {
        Out(b, n);
        Gen(b, n);
    } 
	while (!IsLast(b, n));
    Out(b, n);
}
