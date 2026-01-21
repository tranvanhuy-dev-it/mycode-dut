#include <iostream>
using namespace std;

class Teacher
{
private:
    string namet;
    int age;
public:
    Teacher(string = "", const int & = 0);
    ~Teacher();
    friend ostream& operator<<(ostream&, const Teacher&);
};

Teacher::Teacher(string s, const int& a)
    : namet(s), age(a)
    {

    }

Teacher::~Teacher()
{
}

ostream& operator<<(ostream& o, const Teacher& t)
{
    o << t.namet << ", " << t.age << endl;
    return o; 
}
