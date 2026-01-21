#include "SinhVien.h"

SinhVien::SinhVien() {}

SinhVien::SinhVien(SinhVien &s) : Person(s)
{
    this->id = s.id;
    this->lsh = s.lsh;
    this->gpa = s.gpa;
}

SinhVien::SinhVien(char *name, int age, char *address, bool gender, char *id, LopSinhHoat *lsh, double gpa)
    : Person(name, age, address, gender), id(id), lsh(lsh), gpa(gpa) {}

SinhVien::~SinhVien() {}

ostream& operator<<(ostream& o, const SinhVien& s)
{
  o << "Ho Ten: " << s.name 
    << "    MSSV: " << s.id
    << "    Lop SH:" << s.lsh->get_name()
    << "    GPA: " << s.gpa
    << "\nTuoi: " << s.age 
    << "    Dia Chi: " << s.address 
    << "    GioiTinh" << s.gender
    << endl;
return o;
}

istream& operator>>(istream& in, SinhVien& s)
{
    cout << "Ho Ten: "; in >> s.name;
    cout << 
}