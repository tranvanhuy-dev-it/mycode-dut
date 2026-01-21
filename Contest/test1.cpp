#include <iostream>

using namespace std;

int a[10] = {1, 2, 3, 4, 1, 1, 3, 4, 1, 3};
int x = 1;
int res = 0;

void Sox(int l, int r) {
    if (l == r) {
        if (a[l] == x) {
            res++;
        }
    } else {
        int mid = (l + r) / 2;
        Sox(l, mid);    
        Sox(mid + 1, r);
    }
}

int main() {

    Sox(0, 9);
    cout << res;
    return 0;
}