#include "Exp.h"

class MyExp : public Exp
{
private:
int n;
public:
MyExp(string = "", const int& = 1);
~MyExp();
friend ostream& operator<<(ostream&, const MyExp&);
};

MyExp::MyExp(string s, const int& n)
    : Exp(s), n(n)
{
}

MyExp::~MyExp()
{
}

ostream& operator<<(ostream& o, const MyExp& e)
{
    o << e.msg << ", " << e.n << endl;
    return o;
}

