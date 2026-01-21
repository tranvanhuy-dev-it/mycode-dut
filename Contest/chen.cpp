#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    while (q--)
    {
        int i, x;
        cin >> i >> x;
        a.emplace(a.begin() + i - 1, x);
        for (auto x : a) cout << x << " ";
        cout << endl;
    }
    return 0;
}