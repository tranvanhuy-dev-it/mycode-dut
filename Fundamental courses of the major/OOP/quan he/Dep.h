#include "Teacher.h"
class Dep
{
private:
    string namep;
    Teacher *t;

public:
    Dep(Teacher * = nullptr, string = "");
    ~Dep();
    friend ostream &operator<<(ostream &, const Dep &);
};

Dep::Dep(Teacher *t, string s)
    : namep(s), t(t)
{
}

Dep::~Dep()
{
}

ostream &operator<<(ostream &o, const Dep &d)
{
    o << d.namep << " " << *(d.t) << endl;
    return o;
}