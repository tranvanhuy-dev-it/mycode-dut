#include<iostream>

using namespace std;

int main() {

    string s;
    getline(cin, s);
    int len = s.size();
    bool istrue = true;
    for (int i = 0; i <= len/2 - 1; i++) {
        if (s[i] != s[len - 1 - i]) {
            istrue = false;
            break;
        }
    }
    if (istrue) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}