#include "Lecturer.h"

Lecturer::Lecturer() {}

Lecturer::Lecturer(Lecturer& l) : Person(l)
{
    this->id = l.id;
    this->professor = l.professor;
}

Lecturer::Lecturer(char *name, int age, char *address, bool gender, char *id, char *professor) 
 : Person(name, age, address, gender), id(id), professor(professor) {}