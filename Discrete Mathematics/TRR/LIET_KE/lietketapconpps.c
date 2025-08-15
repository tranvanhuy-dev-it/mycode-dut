#include <stdio.h>

void Out(int n, int a[]){
    for (int i = 1; i <= n; i++){
        if (a[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void Init(int n, int a[]){
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}

int IsLast(int n, int a[]){
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            return 0;
        }
    }
    return 1; 
}

void Gen(int n, int a[]) {
    int i = n;
    while (i > 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i > 0) {
        a[i] = 1;
    }
}

void Methor(int n, int a[]) {
    Init(n, a);
    Out(n, a);
    int stop = IsLast(n, a);
    while(stop==0) {
        Gen(n, a);
        Out(n, a);
        stop = IsLast(n, a);
    }
}

int main() {
    int n, a[1001];
    scanf("%d", &n);
    Methor(n, a);
    return 0;
}
