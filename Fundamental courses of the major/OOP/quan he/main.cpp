#include "Dep.h"
#include <iostream>
using namespace std;

int main()
{
    Teacher *t = new Teacher("VNA", 31);
    Dep *d = new Dep(t, "CNTT");
    cout << *d;
    delete d;
    cout << *t;
    return 0;
}