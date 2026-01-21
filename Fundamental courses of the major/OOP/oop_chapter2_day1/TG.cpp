#include "TG.h"
#include <iostream>
using namespace std;

TG::TG(const Point& a, const Point& b, const Point& c)
    :A(a), B(b)
{
    this->C = c;
}

TG::TG(const int& a, const int& b, const int& c, const int& d, const int& e, const int& f)
    :A(a, b), B(c, d), C(e, f)
{
}

TG::~TG()
{
    cout << "Huy TG";
}

void TG::showTG()
{
    (this->A).show();
    (this->A).show();
    (this->A).show();
}

