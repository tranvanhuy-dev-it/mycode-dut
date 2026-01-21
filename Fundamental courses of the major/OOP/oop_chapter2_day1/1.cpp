#include<iostream>

using namespace std;

void hoanvi(int &m, int &n) {
    int temp = m;
    m = n;
    n = temp;
}

void A() {
    int x = 2;
    static int y = 5;
    x++;
    y++;
    cout << "x = " << x << ", y = " << y << endl; 
}

int main() {

    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    hoanvi(m, n);
    cout << "m = " << m << "n = ";
    return 0;
}