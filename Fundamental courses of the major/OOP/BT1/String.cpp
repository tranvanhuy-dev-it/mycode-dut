#include "String.h"

using namespace std;

String::String(int n)
{
    this->n = n;
    this->p = new char[this->n];
}

ostream& operator<<(ostream& o, const String& s)
{
    for (int i = 0; i < s.n; i++)
    {
        o << *(s.p + i);
    }
    return o;
}

istream& operator>>(istream& in, String& s)
{
    for (int i = 0; i < s.n; i++)
    {
        cout << "s[" << i << "] = ";
        in >> *(s.p + i);
    }
    return in;
}

const String &String::operator=(const String& s)
{
    if (this != &s)
    {
        cout << "=" << endl;
        delete[] this->p;
        this->n = s.n;
        this->p = new char[this->n];
        for (int i = 0; i < this->n; i++)
        {
            this->p[i] = *(s.p + i);
        }
    }
    return (*this);
}

char& String::operator[](const int& index)
{
    static char NGU = '\0';
    if (index >= 0 && index < this->n)
        return *(this->p + index);
    else
        return NGU;
}

String& String::operator+=(const String& s)
{
    int slen = s.n;
    int thislen = this->n;
    char* newChar = new char[slen + thislen];
    for (int i = 0; i < thislen ; i++)
    {
        newChar[i] = this->p[i];
    }
    for (int i = thislen; i < slen + thislen; i++)
    {
        newChar[i] = s.p[i];
    }
    delete[] this->p;
    this->p = newChar;
    this->n = slen + thislen;
    return (*this);
}





