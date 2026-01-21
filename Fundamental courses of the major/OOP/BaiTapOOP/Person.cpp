#include "Person.h"
#include "lib.h"

Person::Person()
{
    name = nullptr;
    address = nullptr;
    age = 0;
    gender = true;
}

Person::Person(const Person &p)
{
    this->gender = p.gender;
    this->age = p.age;

    this->name = new char[Strlen(p.name) + 1];
    Strcpy(this->name, p.name);

    this->address = new char[Strlen(p.address) + 1];
    Strcpy(this->address, p.address);
}

Person::Person(const char *name, int age, const char *address, bool gender)
    : age(age), gender(gender)
{
    if (name)
    {
        this->name = new char[Strlen(name) + 1];
        Strcpy(this->name, name);
    }
    else
        this->name = nullptr;

    if (address)
    {
        this->address = new char[Strlen(address) + 1];
        Strcpy(this->address, address);
    }
    else
        this->address = nullptr;
}

Person::~Person()
{
    delete[] name;
    delete[] address;
}
