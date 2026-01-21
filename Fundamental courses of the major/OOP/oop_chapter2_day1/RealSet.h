#include "IntSet.h"

class RealSet
{
private:
    double *p;
    int n;
public:
    RealSet(const int& = 2);
    ~RealSet();
    void ShowRealSet();
    friend void IntSet::SetToReal(RealSet &);
};
