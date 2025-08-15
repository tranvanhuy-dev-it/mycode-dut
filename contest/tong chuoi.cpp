#include<iostream>

using namespace std;

int main() {

    string s;
    getline(cin, s);
    long  long T = 0;
    for (char c : s) {
        if (c == '-') continue;
        T += c - '0';
    }
    cout << T << "\n";
    return 0;
}