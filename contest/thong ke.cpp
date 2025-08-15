#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int A[26] = {}; 

    for (char c : s) {
        if (isalpha(c)) {
            c = tolower(c);      
            A[c - 'a']++;        
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
