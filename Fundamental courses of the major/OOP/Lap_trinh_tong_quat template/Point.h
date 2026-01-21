// khai bao lop
#include <iostream>

using namespace std;

class Point
{
protected:
    int xVal;
    int yVal;
public:
    // Constructor - hàm dựng
    // Destructor - hàm hủy
    // Point();
    Point(const int & = 1, const int & = 1);
    ~Point();
    friend ostream &operator<<(ostream &, const Point &);
};