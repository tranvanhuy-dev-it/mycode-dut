#include "Lecturer.h"
#include "lib.h"

Lecturer::Lecturer() : Person(), id(nullptr), professor(nullptr) {}

Lecturer::Lecturer(const Lecturer &l) : Person(l)
{
    this->id = new char[Strlen(l.id) + 1];
    Strcpy(this->id, l.id);

    this->professor = new char[Strlen(l.professor) + 1];
    Strcpy(this->professor, l.professor);
}

Lecturer::Lecturer(const char *name, int age, const char *address, bool gender, const char *id, const char *professor)
    : Person(name, age, address, gender)
{
    this->id = new char[Strlen(id) + 1];
    Strcpy(this->id, id);

    this->professor = new char[Strlen(professor) + 1];
    Strcpy(this->professor, professor);
}

Lecturer::~Lecturer()
{
    delete[] id;
    delete[] professor;
}

ostream &operator<<(ostream &o, const Lecturer &l)
{
    o << "MSGV: " << l.id
      << "  Ho Ten: " << l.name
      << "  Tuoi: " << l.age
      << "  Gioi Tinh:" << (l.gender ? "Nam" : "Nu")
      << "  Dia Chi: " << l.address
      << "  Cap Bac: " << l.professor
      << endl;
    return o;
}

istream &operator>>(istream &in, Lecturer &l)
{
    char temp[100];

    cout << "Ho Ten: ";
    in.getline(temp, 100);
    delete[] l.name;
    l.name = new char[Strlen(temp) + 1];
    Strcpy(l.name, temp);

    cout << "Tuoi: ";
    in >> l.age;
    in.ignore();

    cout << "Gioi Tinh (Nam/Nu): ";
    in.getline(temp, 100);
    if (temp[0] == 'N' || temp[0] == 'n')
    {
        if (tolower(temp[1]) == 'a')
            l.gender = true;
        else if (tolower(temp[1]) == 'u')
            l.gender = false;
    }
    else
    {
        l.gender = false; 
    }

    cout << "Dia Chi: ";
    in.getline(temp, 100);
    delete[] l.address;
    l.address = new char[Strlen(temp) + 1];
    Strcpy(l.address, temp);

    char id_temp[100] = "102";
    char *ten = catTen(l.name);
    noiChuoi(id_temp, ten);
    delete[] ten;

    delete[] l.id;
    l.id = new char[Strlen(id_temp) + 1];
    Strcpy(l.id, id_temp);

    cout << "Cap Bac: ";
    in.getline(temp, 100);
    delete[] l.professor;
    l.professor = new char[Strlen(temp) + 1];
    Strcpy(l.professor, temp);

    return in;
}
