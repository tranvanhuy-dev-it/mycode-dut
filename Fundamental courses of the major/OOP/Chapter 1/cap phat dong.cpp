#include<iostream>

using namespace std;

int main() {

    int n;
    cout << "n = ";
    cin >> n;
    int *p1 = new int[n]; //cap phat bo nho mang dong mot chieu
    for (int i = 0; i < n; i++) {
        cout << "pt = ";
        cin >> *(p1 + i);
    } 
    for (int i = 0; i < n; i++) {
        cout << *(p1 + i) << " ";
    }
    cout << endl;
    delete[] p1; //giai phong mang dong
    //cap phat dong cho mang hai chieu
    int r, c;
    cout << "r = ";
    cin >> r;
    cout << "c = ";
    cin >> c;
    int **p = new int*[r];
    for (int i = 0; i < r; i++) {
        *(p + i) = new int[c];
        for (int j = 0; j < c; j++) {
            cout << "p[" << i << "][" << j << "] = ";
            cin >> *(*(p + i) + j);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << *(*(p + i) + j) << " ";
        }
        cout << endl;
    }
    return 0;
}