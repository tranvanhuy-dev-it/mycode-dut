#include <iostream>
#include <cstdlib>
#include<cctype>  
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int len = s.size();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            cnt+=s[i] - '0';
        }
    }
    cout << cnt;
    return 0;
}
