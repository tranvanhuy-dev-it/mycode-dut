#include "SinhVien.h"
#include "lib.h"

SinhVien::SinhVien() : Person(), id(nullptr), lsh(nullptr), gpa(0.0) {}

SinhVien::SinhVien(const SinhVien &sv)
{
    if (sv.name)
    {
        this->name = new char[Strlen(sv.name) + 1];
        Strcpy(this->name, sv.name);
    }
    else
        this->name = nullptr;

    if (sv.id)
    {
        this->id = new char[Strlen(sv.id) + 1];
        Strcpy(this->id, sv.id);
    }
    else
        this->id = nullptr;

    if (sv.address)
    {
        this->address = new char[Strlen(sv.address) + 1];
        Strcpy(this->address, sv.address);
    }
    else
        this->address = nullptr;

    this->age = sv.age;
    this->gender = sv.gender;
    this->gpa = sv.gpa;
    this->lsh = sv.lsh; 
}

SinhVien::SinhVien(char *name, int age, char *address, bool gender, char *id, LopSinhHoat *lsh, double gpa)
    : Person(name, age, address, gender), lsh(lsh), gpa(gpa)
{
    if (id)
    {
        this->id = new char[Strlen(id) + 1];
        Strcpy(this->id, id);
    }
    else
        this->id = nullptr;
}

SinhVien::~SinhVien()
{
    delete[] id;
}

SinhVien &SinhVien::operator=(const SinhVien &sv)
{
    if (this == &sv)
        return *this;

    delete[] id;

    if (sv.id)
    {
        id = new char[Strlen(sv.id) + 1];
        Strcpy(id, sv.id);
    }
    else
        id = nullptr;

    delete[] name;
    delete[] address;

    if (sv.name)
    {
        name = new char[Strlen(sv.name) + 1];
        Strcpy(name, sv.name);
    }
    else
        name = nullptr;

    if (sv.address)
    {
        address = new char[Strlen(sv.address) + 1];
        Strcpy(address, sv.address);
    }
    else
        address = nullptr;

    age = sv.age;
    gender = sv.gender;
    gpa = sv.gpa;
    lsh = sv.lsh;

    return *this;
}

void SinhVien::set_lsh(LopSinhHoat *cls)
{
    this->lsh = cls;
}

char *SinhVien::get_id() { return id; }

void SinhVien::set_gpa(int new_gpa) { this->gpa = new_gpa; }

char *SinhVien::get_name() { return name; }

ostream &operator<<(ostream &o, const SinhVien &s)
{
    o << "MSSV: " << s.id
      << "  Ho Ten: " << s.name
      << "  Lop SH: " << s.lsh->get_name()
      << "  GPA: " << s.gpa
      << "  Tuoi: " << s.age
      << "  Gioi Tinh: " << (s.gender ? "Nam" : "Nu")
      << "  Dia Chi: " << s.address
      << endl;
    return o;
}
istream &operator>>(istream &in, SinhVien &s)
{
    char temp[100];

    cout << "Ho Ten: ";
    in.getline(temp, 100);
    delete[] s.name;
    s.name = new char[Strlen(temp) + 1];
    Strcpy(s.name, temp);

    cout << "Tuoi: ";
    in >> s.age;
    in.ignore();

    cout << "Gioi Tinh (Nam/Nu): ";
    in.getline(temp, 100);
    if (temp[0] == 'N' || temp[0] == 'n')
    {
        if (tolower(temp[1]) == 'a')
            s.gender = true;
        else if (tolower(temp[1]) == 'u')
            s.gender = false;
    }
    else
    {
        s.gender = false;
    }

    cout << "Dia Chi: ";
    in.getline(temp, 100);
    delete[] s.address;
    s.address = new char[Strlen(temp) + 1];
    Strcpy(s.address, temp);

    while (true)
    {
        cout << "MSSV (9 ky tu, khong bat dau bang 0): ";
        in.getline(temp, 100);

        if (Strlen(temp) != 9)
        {
            cout << "MSSV phai co 9 ky tu. Nhap lai.\n";
            continue;
        }
        if (temp[0] == '0')
        {
            cout << "MSSV khong duoc bat dau bang 0. Nhap lai.\n";
            continue;
        }

        bool ok = true;
        for (int i = 0; i < 9; i++)
        {
            if (temp[i] < '0' || temp[i] > '9')
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            cout << "MSSV chi duoc chua so nguyen. Nhap lai.\n";
            continue;
        }
        delete[] s.id;
        s.id = new char[10];
        Strcpy(s.id, temp);
        break;
    }

    s.gpa = 0;

    return in;
}