#include <iostream>
using namespace std;

class Complex
{
    double R, I;
public:
    Complex(double, double);
    friend Complex operator+(Complex, Complex);
    friend ostream& operator<<(ostream &, Complex);
};

// Định nghĩa constructor 2 tham số
Complex::Complex(double R, double I) : R(R), I(I)
{
}

// Định nghĩa constructor 1 tham số
// Lưu ý: Code trong ảnh gán cả R và I bằng tham số truyền vào

// Định nghĩa toán tử cộng
Complex operator+(Complex obj1, Complex obj2)
{
    return Complex(obj1.R + obj2.R, obj1.I + obj2.I);
}

// Định nghĩa toán tử xuất (cout)
ostream & operator<<(ostream &o, Complex obj)
{
    o << obj.R << "," << obj.I;
    return o;
}

int main()
{
    Complex obj1(3, 4);
    
    // Khi cộng obj1 + 6:
    // Số 6 được chuyển thành Complex(6) => R=6, I=6 (do constructor 1 tham số)
    // Kết quả phép cộng: (3+6, 4+6) = (9, 10)
    Complex obj2 = obj1 + 5;
    
    cout << obj2; // In ra: 9,10
    
    system("pause");
    return 0;
}