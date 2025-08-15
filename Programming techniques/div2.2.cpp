#include <iostream>
#include <vector>
using namespace std;

vector<string> tranvanhuy(int t, vector<pair<int, int>> solan) {
    vector<string> results;
    for (auto &cas : solan) {
        int n = cas.first;
        int k = cas.second;
        int nambatdau = max(1, n - k + 1);
        long long total_leaves = (n * (n + 1)) / 2 - ((nambatdau - 1) * nambatdau) / 2;
        if (total_leaves % 2 == 0) {
            results.push_back("YES");
        } else {
            results.push_back("NO");
        }
    }
    return results;
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, int>> solan(t);
    for (int i = 0; i < t; ++i) {
        cin >> solan[i].first >> solan[i].second;
    }
    vector<string> results = tranvanhuy(t, solan);
    for (const string &result : results) {
        cout << result << endl;
    }
    return 0;
}
