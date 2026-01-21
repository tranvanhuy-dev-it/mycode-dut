#include "Point3D.h"
#include <iostream>

using namespace std;

int main()
{

    Point p1(1, 2);
    Point3D p2(3, 4, 5);
    Point* p; Point3D* pp;
                                    
    p = &p2;
    pp = static_cast<Point3D*>(&p1);
    p->show();
    pp->show();

    Point p3(p1);
    Point p4(p2);
    return 0;
}