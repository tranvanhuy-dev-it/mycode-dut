#include<iostream>

using namespace std;

int x = 2;

int &A() {

    return x;
}

int &B() {
    static int x = 4;
    return x;
}

int main() {

    enum Color {
        R,
        G,
        B = 4,
        Y = 3
    };

    Color c = B;

    cout << c << endl;

    A() = 6;
    cout << x << endl;
    cout << A()++ << endl;
    return 0;
}