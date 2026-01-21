#include "Point.h"

class Point3D : public Point
{
protected:
    int zVal;
public:
    Point3D(const int& = 2, const int& = 2, const int& = 2);
    ~Point3D();
    void show();
    void show3D();
};