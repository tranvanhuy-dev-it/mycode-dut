#include "Point.h"

using namespace std;

Point::Point(const int& x, const int& y)
{
    this->xVal = x; //dung this-> de trinh bien dich phan biet
    this->yVal = y;
}

Point::~Point() { 
    cout << "Huy Point\n";    
}


ostream& operator<<(ostream& o, const Point& p)
{
    o << "Point(" << p.xVal << "," << p.yVal << ")\n";
    return o;
}
