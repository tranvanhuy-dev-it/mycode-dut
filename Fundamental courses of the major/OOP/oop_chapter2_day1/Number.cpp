#include "Number.h"

Number::Number(const double& d)
        :d(d)
        {
        }
Number::~Number()
{
}

Number::operator int()
{
    return int(this->d);
}

Number::operator double()
{
    return this->d;
}