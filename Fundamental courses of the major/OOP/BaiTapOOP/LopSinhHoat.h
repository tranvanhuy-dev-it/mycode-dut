#pragma once
#include "Lecturer.h"
#include <iostream>

using namespace std;

class SinhVien;
class LopSinhHoat
{
private:
    char* name;
    int count;
    Lecturer *lecturer;
    SinhVien *list;
public:
    LopSinhHoat(const LopSinhHoat&);
    LopSinhHoat(const char*, Lecturer*);
    ~LopSinhHoat();
    char* get_name();
    SinhVien* get_list();
    void set_GV(Lecturer *new_gv);
    void addStudent();
    void delStudent();
    void editLecturer();
    void editStudent();
    void update_gpa();
    void searchStudent();

    friend ostream& operator<<(ostream&, const LopSinhHoat&);
    LopSinhHoat& operator=(const LopSinhHoat& cls);
    SinhVien& operator[](int index);
    SinhVien& operator[](const char *);
};