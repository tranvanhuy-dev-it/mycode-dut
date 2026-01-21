#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

class Lecturer : public Person
{
private:
    char *id;
    char *professor;
public:
    Lecturer();
    Lecturer(const Lecturer&);
    Lecturer(const char*, int, const char*, bool, const char*, const char*);
    ~Lecturer();

    friend ostream& operator<<(ostream&, const Lecturer&);
    friend istream& operator>>(istream&, Lecturer&);
};