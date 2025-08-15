#include <iostream>
#include <cstdlib>
#include<cctype>  
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int len = s.size();
    bool hoa = false;
    bool thuong = false;
    bool so = false;
    bool kitu = false;

    if (len >= 8) kitu = true;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            so = true;
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            thuong = true;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            hoa = true;
        }
    }
    if (hoa && thuong && so && kitu) {
        cout << "STRONG";
    } else {
        cout << "WEAK";
    }
    
    return 0;
}
