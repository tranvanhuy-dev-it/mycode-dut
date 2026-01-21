#pragma once
class Person
{
protected:
    char *name;
    int age;
    char *address;
    bool gender;

public:
    Person();
    Person(const Person&);
    Person(const char*, int, const char*, bool);
    ~Person();
};