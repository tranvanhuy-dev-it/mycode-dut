#include <iostream>
#include <sstream>  
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int len = s.size();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I') {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
