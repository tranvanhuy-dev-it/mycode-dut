#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int max = 0, curr = 0;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] > 0) curr ++;
        else curr = 0;
        if (curr > max) max = curr;
    }
    cout << max;
    return 0;
}