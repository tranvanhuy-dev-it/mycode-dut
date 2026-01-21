#include <iostream>

class Person
{
protected:
    char *name;
    int age;
    char *address;
    bool gender;

public:
    Person();
    Person(Person&);
    Person(char*, int, char*, bool);
    ~Person();
};