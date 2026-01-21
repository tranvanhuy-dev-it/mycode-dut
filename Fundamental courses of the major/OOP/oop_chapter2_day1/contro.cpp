#include<iostream>

using namespace std;

void show (char *str) {
    cout << str << endl;
}

int main() {

    int x = 10, y = 20;
    int *p1, *p2;
    p1 = &x; p2 = &y;
    
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    *p1 = 50; *p2 = 90;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    *p1 = *p2;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    const int* p3 = &x; //con tro hang -> chi duoc phep lay gia tri
    cout << *p3 << endl;
    //cout << (*p3++) << endl; ->sai
    int* const p4 = &y; //hang con tro -> chi duoc phep tro vao mot dia chi duy nhat -> duoc phep truy cap hai chieu
    //p4 = &y -> sai

    //ep kieu bo hang
    const char *str = "DUT";
    show(const_cast<char*>(str));

    return 0;
}