#include "Point3D.h"

Point3D::Point3D(const int& x, const int& y, const int& z)
    :Point(x, y)
{
    this->zVal = z;
}

Point3D::~Point3D()
{
    cout << "Huy Point3D" << endl;
}

void Point3D::show()
{
    this->show();
    cout << this->zVal << endl;
}

void Point3D::show3D()
{
    cout << "Print3D(" << this->xVal << ", " << this->yVal << ", " << this->zVal << ")" << endl; 
}