#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string word, result = "";

    while (ss >> word) {
        for (int i = 0; i < word.size(); i++) {
            word[i] = tolower(word[i]);
        }
        word[0] = toupper(word[0]);

        if (!result.empty()) result += " ";
        result += word;
    }

    cout << result << "\n";
    return 0;
}
