#include "LopSinhHoat.h"
#include "SinhVien.h"
#include "lib.h"
#include <iostream>

using namespace std;

LopSinhHoat::LopSinhHoat(const LopSinhHoat &cls)
{
    this->name = new char[Strlen(cls.name) + 1];
    Strcpy(this->name, cls.name);
    this->count = cls.count;
    if (cls.lecturer)
        this->lecturer = new Lecturer(*cls.lecturer);
    else
        this->lecturer = nullptr;

    if (count > 0)
    {
        this->list = new SinhVien[count];
        for (int i = 0; i < count; i++)
            this->list[i] = cls.list[i];
    }
    else
        list = nullptr;
}
LopSinhHoat::LopSinhHoat(const char *name, Lecturer *l)
    : list(nullptr), count(0)
{
    this->name = new char[Strlen(name) + 1];
    Strcpy(this->name, name);

    lecturer = new Lecturer(*l);

    cout << "\nNhap si so lop " << name << ": ";
    cin >> count;
    cin.ignore();

    if (count > 0)
    {
        list = new SinhVien[count];
        for (int i = 0; i < count; i++)
        {
            cout << "\nNhap sinh vien thu " << i + 1 << "\n";
            cin >> list[i];
            list[i].set_lsh(this);
        }
    }
}

LopSinhHoat::~LopSinhHoat()
{
    delete[] name;
    delete[] list;
    delete lecturer;
}

char *LopSinhHoat::get_name() { return name; }
SinhVien *LopSinhHoat::get_list() { return list; }
void LopSinhHoat::set_GV(Lecturer *new_gv) { this->lecturer = new_gv; }

void LopSinhHoat::addStudent()
{
    SinhVien newSv;
    cout << "Nhap thong tin sinh vien moi:\n";
    cin.ignore();
    cin >> newSv;
    newSv.set_lsh(this);

    SinhVien *newList = new SinhVien[count + 1];

    for (int i = 0; i < count; i++)
        newList[i] = list[i];

    newList[count] = newSv;

    delete[] list;
    list = newList;
    count++;

    cout << "Da them sinh vien thanh cong!\n";
}

void LopSinhHoat::delStudent()
{
    if (count == 0)
    {
        cout << "Lop hoc rong, khong co sinh vien de xoa.\n";
        return;
    }

    char id[100];
    cout << "Nhap MSSV cua sinh vien can xoa: ";
    cin.ignore();
    cin.getline(id, 100);

    int idx = -1;
    for (int i = 0; i < count; i++)
    {
        if (Strcmp(list[i].get_id(), id) == 0)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        cout << "Khong tim thay sinh vien voi MSSV: " << id << endl;
        return;
    }

    SinhVien *newList = nullptr;
    if (count > 1)
    {
        newList = new SinhVien[count - 1];
        int j = 0;
        for (int i = 0; i < count; i++)
        {
            if (i != idx)
            {
                newList[j++] = list[i];
            }
        }
    }

  
    delete[] list;
    list = newList;
    count--;

    cout << "Da xoa sinh vien voi MSSV: " << id << endl;
}


void LopSinhHoat::editLecturer()
{
    cout << "Nhap thong tin GVCN moi:\n";
    cin.ignore();
    cin >> *(lecturer);
    cout << "Da thay doi thong tin giang vien thanh cong\n";
}

void LopSinhHoat::editStudent()
{
    if (count <= 0)
    {
        cout << "Danh sach lop rong\n";
        return;
    }

    char id[100];
    cout << "Nhap MSSV sinh vien can sua: ";
    cin.ignore();
    cin.getline(id, 100);

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (Strcmp(list[i].get_id(), id) == 0)
        {
            cout << "Nhap thong tin sinh vien moi:\n";
            cin >> list[i];
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Khong tim thay sinh vien voi MSSV: " << id << endl;
}

void LopSinhHoat::update_gpa()
{
    if (count <= 0)
    {
        cout << "Danh sach lop rong\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        double new_gpa;
        do
        {
            cout << list[i].get_name() << ": ";
            cin >> new_gpa;

            if (new_gpa < 0 || new_gpa > 4)
                cout << "GPA phai tu 0 den 4. Nhap lai.\n";

        } while (new_gpa < 0 || new_gpa > 4);

        list[i].set_gpa(new_gpa);
    }

    cout << "Da cap nhat diem thanh cong\n";
}


void LopSinhHoat::searchStudent()
{
    if (count <= 0)
    {
        cout << "Danh sach lop rong\n";
        return;
    }

    char id[100];
    cout << "Nhap MSSV sinh vien can sua: ";
    cin.ignore();
    cin.getline(id, 100);

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (Strcmp(list[i].get_id(), id) == 0)
        {
            cout << "Thong tin sinh vien co MSSV: " << id << ":\n\n";
            cout << list[i];
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Khong tim thay sinh vien voi MSSV: " << id << endl;
}

ostream &operator<<(ostream &o, const LopSinhHoat &cls)
{
    o << "\nLop: " << cls.name
      << "     Si So: " << cls.count << endl
      << "GVCN - " << *(cls.lecturer)
      << "\nSinh Vien:\n";

    for (int i = 0; i < cls.count; i++)
    {
        o << "  " << i + 1 << ": " << cls.list[i] << "\n";
    }
    return o;
}

SinhVien &LopSinhHoat::operator[](int index)
{
    if (index < 0 || index >= count)
    {
        throw out_of_range("Index khong hop le!");
    }
    return list[index];
}

SinhVien &LopSinhHoat::operator[](const char *id)
{
    for (int i = 0; i < count; i++)
    {
        if (Strcmp(list[i].get_id(), id) == 0)
            return list[i];
    }
    throw out_of_range("Sinh vien khong hop le!");
}

LopSinhHoat &LopSinhHoat::operator=(const LopSinhHoat &cls)
{
    if (this == &cls)
        return *this;

    delete[] name;
    delete[] list;

    name = new char[Strlen(cls.name) + 1];
    Strcpy(name, cls.name);

    count = cls.count;
    if (cls.lecturer)
        lecturer = new Lecturer(*cls.lecturer);
    else
        lecturer = nullptr;

    if (count > 0)
    {
        list = new SinhVien[count];
        for (int i = 0; i < count; i++)
        {
            list[i] = cls.list[i];
            list[i].set_lsh(this);
        }
    }
    else
        list = nullptr;

    return *this;
}
