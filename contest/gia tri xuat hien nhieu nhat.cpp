#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<int,int> freq;
    for (int x : a) {
        freq[x]++;
    }

    int res = 0;       
    int maxCount = 0;   

    for (auto &p : freq) {
        if (p.second > maxCount) {
            maxCount = p.second;
            res = p.first;
        } 
        else if (p.second == maxCount && p.first > res) {
            res = p.first;
        }
    }

    cout << res << endl;

    return 0;
}
