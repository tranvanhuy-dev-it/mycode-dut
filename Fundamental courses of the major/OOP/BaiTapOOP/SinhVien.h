#pragma once
#include "Person.h"
#include "LopSinhHoat.h"
#include <iostream>

using namespace std;

class SinhVien : public Person
{
private:
    char* id;
    LopSinhHoat* lsh;
    double gpa;
public:
    SinhVien();
    SinhVien(const SinhVien&);
    SinhVien(char*, int, char*, bool, char*, LopSinhHoat*, double);
    ~SinhVien();
    SinhVien& operator=(const SinhVien&);
    void set_lsh(LopSinhHoat*);
    char* get_id();
    void set_gpa(int);
    char* get_name();

    friend ostream& operator<<(ostream&, const SinhVien&);
    friend istream& operator>>(istream&, SinhVien&);
};