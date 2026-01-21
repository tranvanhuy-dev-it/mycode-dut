#include<iostream>
using ul = unsigned long long;
using namespace std;

int main() {
    ul n, x;
    cin >> n;

    ul c0 = 0, c1 = 0, c2 = 0;

    for (ul i = 0; i < n; i++) {
        cin >> x;
        if (x % 3 == 0) c0++;
        else if (x % 3 == 1) c1++;
        else c2++;
    }

    ul cnt = 0;
    cnt += c0 * (c0 - 1) / 2; 
    cnt += c1 * c2;           

    cout << cnt << "\n";
    return 0;
}
