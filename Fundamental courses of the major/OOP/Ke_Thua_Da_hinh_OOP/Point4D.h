#include "Point3D.h"

class Point4D : public Point3D
{
private:
    int tVal;
public:
    Point4D(const int& = 2, const int& = 2, const int& = 2, const int& = 2);
    ~Point4D();
    void show();
    void show4D();
};