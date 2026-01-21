#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        vector<char> S;

        for (char ch : s) {
            if (ch != '*') {
                S.push_back(ch);
            } else {
                if (!S.empty()) {
                    int min = 0;
                    for (int i = 1; i < S.size(); i++) {
                        if (S[i] < S[min]) min = i;
                    }
                    S.erase(S.begin() + min);
                }
            }
        }

        return string(S.begin(), S.end());
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution sol;
    string result = sol.clearStars(s);
    cout << result << endl;

    return 0;
}
