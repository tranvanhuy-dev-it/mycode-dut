#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string expr;
    cin >> expr;

    stack<long long> stk;
    long long num = 0;
    char prev_op = '+';
    int n = expr.size();

    for (int i = 0; i < n; i++) {
        char c = expr[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || i == n - 1) {
            if (prev_op == '+') {
                stk.push(num);
            } else if (prev_op == '-') {
                stk.push(-num);
            } else if (prev_op == '*') {
                long long top = stk.top();
                stk.pop();
                stk.push(top * num);
            }
            prev_op = c;
            num = 0;
        }
    }

    long long result = 0;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    cout << result << "\n";

    return 0;
}
