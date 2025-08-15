#include<iostream>
#include<vector>

using namespace std;


void nguyento(int value) {
    vector<bool> A(value + 1, true);
    A[0] = A[1] = false;
    for (int i = 2; i * i <= value; i++) {
        if (A[i]) {
            for (int j = i*i; j <= value; j+= i) {
                A[j] = false;
            }
        }
    }

    for (int i = 2; i <= value; i++) {
        if (A[i] == true) {
            cout << i << " ";
        }
    }
}

int main() {

    int n;
    cin >> n;

    nguyento(n);
    return 0;
}