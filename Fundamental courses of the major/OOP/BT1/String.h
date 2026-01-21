#include <string>
#include <iostream>

using namespace std;

class String
{
private:
    char *p;
    int n;
public:
    String(int);
    ~String();
    friend ostream& operator<<(ostream&,const String&);
    friend istream& operator>>(istream&, String&);
    const String& operator=(const String&);
    char& operator[](const int&);
    String& operator+=(const String&);
};