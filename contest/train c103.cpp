#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 1) {
            cout << 1 << '\n' << 1 << '\n';
        } else if (n == 2) {
            cout << 2 << '\n';
            cout << 2 << ' ' << 3 << '\n';
        } else {
            cout << 2 << '\n';
            cout << n << ' ' << n * (n + 1LL) << '\n';
        }
    }
    
    return 0;
}