#include <bits/stdc++.h>
using namespace std;

bool is_difficult(const string& s) {
    for (int i = 0; i + 2 < s.size(); ++i) {
        if (s.substr(i, 3) == "FFT" || s.substr(i, 3) == "NTT") {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string res = s;
        sort(res.begin(), res.end());
        if (is_difficult(res)) {
            reverse(res.begin(), res.end());
        }

        cout << res << '\n';
    }
    return 0;
}
