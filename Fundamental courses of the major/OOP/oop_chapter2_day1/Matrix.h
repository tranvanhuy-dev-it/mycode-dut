#include <iostream>
using namespace std;

class Matrix
{
private:
    int **p;
    int r, c;
public:
    Matrix(const int&, const int&);
    ~Matrix();
    friend ostream& operator<<(ostream&, const Matrix&);
    friend istream& operator>>(istream&, Matrix&);
    int& operator()(const int&, const int&);
};
