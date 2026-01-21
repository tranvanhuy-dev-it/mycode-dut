#include<iostream>

using namespace std;

int main() {

    int A[4];
    int *p = A;

    cout << p << ", " << A << "," << &A[0] << endl;
    cout << p + 1 << ", " << &A[1] << endl;
    cout << *(p + 1) << ", " << A[1] << endl;
    cout << "--------------\n";


    int B[2][3] = {1, 3, 5, 2, 4, 6};

    cout << B << ", " << &B[0][0] << endl;
    cout << *(B + 1) << ", " << &B[1][0] << endl;
    cout << *(B + 1) + 1 << ", " << &B[1][1] << endl;
    cout << *(*(B + 1) + 1) << ", " << B[1][1] << endl;

    return 0;
}