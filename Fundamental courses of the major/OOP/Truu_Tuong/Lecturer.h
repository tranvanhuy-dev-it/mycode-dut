#include "Person.h"

class Lecturer : public Person
{
private:
    char *id;
    char *professor;

public:
    Lecturer();
    Lecturer(Lecturer &);
    Lecturer(char *, int, char *, bool, char *, char *);
    ~Lecturer();
};