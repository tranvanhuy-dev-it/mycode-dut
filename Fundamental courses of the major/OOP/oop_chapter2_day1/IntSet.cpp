#include "IntSet.h"
#include <iostream>
using namespace std;

IntSet::IntSet(const int& n)
    : n(n)
{
    this->p = new int[this->n];
    for(int i = 0; i < this->n; i++)
    {
        cout  << "p[" << i << "] = ";
        cin >> *(this->p + i);
    }
}

IntSet::~IntSet()
{
    delete[] this->p;
}

void IntSet::ShowIntSet()
{
    for(int i = 0; i < this->n; i++){
        cout << *(this->p + i) << " ";
    }
    cout << endl;
}

