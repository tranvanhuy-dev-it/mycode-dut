#include <iostream>
#include <sstream>  
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    cout << s;
    return 0;
}
