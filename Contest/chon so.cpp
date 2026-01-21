#include<iostream>
#include<vector>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(n), C(n);

    for (int &x : A) {
        cin >> x;
    }

    for (int &x : B) {
        cin >> x;
    }

    for (int &x : C) {
        cin >> x;
    }



    return 0;
}