#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    int i = 0;
    while(i < n-1) {
        if (s[i] == 'X' && s[i+1] == 'O' || s[i] == 'O' && s[i+1] == 'X') {
            res += 1;
            i += 2; 
        } else {
            i++;
        }  
    }
    
    cout << res << "\n";
    return 0;
}