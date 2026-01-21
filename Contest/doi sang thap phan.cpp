#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    int i = 0;
    long long T = 0;
    for (char c : s) {
        if (c == '1') {
            T += (long long)pow(2, i);
            i++;
        }
        else i++;
    }

    cout << T << "\n";
    return 0;
} 