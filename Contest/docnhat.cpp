#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    set<int> s;
    int l = 0; 
    int sum = 0;
    for (int r = 0; r < n; r++) {
        while (s.count(a[r])) {
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        sum += (r - l + 1);
    }
    cout << sum;
    return 0;
}