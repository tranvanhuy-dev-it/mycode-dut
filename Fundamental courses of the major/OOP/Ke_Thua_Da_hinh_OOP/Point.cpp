#include "Point.h"

using namespace std;


void Point::tt(int x) 
{
    xVal += x;
    yVal += x;
}

void Point::show() 
{
    cout << "(" << xVal << ", " << yVal << ")" << endl;
}

Point::Point(const Point& p)
{
    xVal = p.xVal;
    yVal = p.yVal;
}

Point::Point(const int& x, const int& y)
{
    this->xVal = x; //dung this-> de trinh bien dich phan biet
    this->yVal = y;
}

Point::~Point() { 
    cout << "Huy Point\n";    
}

void Point::set_xVal(const int& x) { xVal = x; }
void Point::set_yVal(const int& y) { yVal = y; }

int Point::get_xVal() const { return xVal; }
int Point::get_yVal() const { return yVal; }

void display(Point p) 
{
    cout << p.xVal << endl;
}

Point operator+(const Point& p1, const Point& p2)
{
    // Point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
    // return p;
    return (p1.xVal + p2.xVal, p1.yVal + p2.yVal);
}

Point Point::operator-(const Point& pp)
{
    // Point p(this->xVal - pp.xVal, this->yVal - pp.yVal);
    // return p;
    return (this->xVal - pp.xVal, this->yVal - pp.yVal);
}

ostream& operator<<(ostream& o, const Point& p)
{
    o << "Point(" << p.xVal << "," << p.yVal << ")\n";
    return o;
}

ostream& operator<<(const Point& p, ostream& o)
{
    o << "Point(" << p.xVal << "," << p.yVal << ")\n";
    return o;
}

istream& operator>>(istream& in, Point &p)
{
    cout << "xVal = ";
    in >> p.xVal;
    cout << "yVal = ";
    in >> p.yVal;
    return in;
}

Point& Point::operator++()
{
    this->xVal++;
    this->yVal++;
    return (*this);
}

const Point Point::operator++(int)
{
    Point bef = (*this);
    this->xVal++;
    this->yVal++;
    return bef;
}