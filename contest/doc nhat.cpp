#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i] == a[j]) {
                a.erase(a.begin() + j);
                j--;
            }
        }
    }

    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}
