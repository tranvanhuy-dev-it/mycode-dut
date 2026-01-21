#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int sum = a + b;

    string s = to_string(sum);


    reverse(s.begin(), s.end());

    int i = 0;
    while (i < s.size() && s[i] == '0') {
        i++;
    }
    cout << s.substr(i) << "\n";

    return 0;
}
