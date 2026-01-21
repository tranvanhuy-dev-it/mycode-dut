#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector(const int &n)
    : n(n)
{
    this->p = new int[this->n];
    cin >> (*this);
}

Vector::Vector(const Vector &v)
    : n(v.n)
{
    cout << "Copy" << endl;
    for (int i = 0; i < n; i++)
    {
        (*this)[i] = *(v.p + i);
    }
}

Vector::~Vector()
{
    delete[] this->p;
}

ostream &operator<<(ostream &o, const Vector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        o << *(v.p + i) << " ";
    }
    o << endl;
    return o;
}

istream &operator>>(istream &in, Vector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        cout << "p[" << i << "] = ";
        in >> v[i];
    }
    return in;
}

int &Vector::operator[](const int &index)
{
    static int NGU = 0;
    if (index >= 0 && index < this->n)
        return *(this->p + index);
    else
        return NGU;
}

const Vector &Vector::operator=(const Vector &v)
{
    if (this != &v)
    {
        cout << "=" << endl;
        delete[] this->p;
        this->n = v.n;
        this->p = new int(this->n);
        for (int i = 0; i < n; i++)
        {
            (*this)[i] = *(v.p + i);
        }
    }
    return *(this);
}