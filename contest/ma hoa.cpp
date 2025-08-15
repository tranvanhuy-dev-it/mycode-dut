#include<iostream>

using namespace std;

int main() {

    string s;
    getline(cin, s);
    int k;
    cin >> k;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') continue;
        s[i] = (s[i] - 'a' + k) % 26 + 'a';
    }
    cout << s;
    return 0;
}