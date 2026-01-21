#include<iostream>


using namespace std;

int sum(int x, int y) {
    return x + y;
}

void Swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

bool td(int a, int b) {
    return a > b;
}

bool gd(int a, int b) {
    return a < b;
}

void sx(int *p, int n, bool (*cmp)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(*(p + i), *(p + j))) {
                Swap(&p[i], &p[j]);
            }
        }
    }
}

int main() {

    int (*p)(int, int);
    p = sum;
    cout << p(1, 2) << endl;

    int B[6] = {3, 6, 1, 8, 2, 0};
    sx(B, 6, td);
    for (int x : B) {
        cout << x << " ";
    }
    cout << endl;

    sx(B, 6, gd);
    for (int x : B) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}