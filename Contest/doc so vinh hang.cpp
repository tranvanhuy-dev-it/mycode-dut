#include<iostream>

using namespace std;

int main() {

    int n;
    do {
        cin >> n;
        if (n != 0) {
            cout << n*n*n*n*n << "\n";
        }
    } while(n != 0);
}