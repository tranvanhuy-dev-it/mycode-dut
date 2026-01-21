// khai bao lop
#include <iostream>

using namespace std;

class Point
{
private:
    int xVal;
    int yVal;
    static int n; // bien tinh
public:
    // Constructor - hàm dựng
    // Destructor - hàm hủy
    // Point();
    Point(const Point &);
    Point(const int & = 1, const int & = 1);
    ~Point();

    void tt(int);
    void show();

    void set_xVal(const int &);
    void set_yVal(const int &);

    int get_xVal() const;
    int get_yVal() const;

    static void shown(); // ham tinh duoc goi ra ngay tren class
    friend void display(Point);
    friend Point operator+(const Point &, const Point &);
    Point operator-(const Point &);
    friend ostream &operator<<(ostream &, const Point &);
    friend ostream &operator<<(const Point &, ostream &);
    friend istream &operator>>(istream &, Point &);
    Point &operator++();
    const Point operator++(int);
};