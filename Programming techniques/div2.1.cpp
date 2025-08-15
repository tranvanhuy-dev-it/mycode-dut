#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y; // nhap n x y
        
        int thoigian = (min(x, y) + n- 1) / min(x, y);
        
        cout << thoigian << endl;
    }
    
    return 0;
}