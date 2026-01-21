#include <iostream>
using namespace std;

template<typename T>
class Vector
{
private:
    T* p;
    int n;
public:
    Vector();  
    Vector(int size, const T& value);
    ~Vector();
    void show();
};

template<typename T>
Vector<T>::Vector() 
{
    cout << "Vevtor md\n";
    p = nullptr;
    n = 0;
}

template<typename T>
Vector<T>::Vector(int size, const T& value)
    : n(size)
{
    cout << "Vevtor ts\n";
    p = new T[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = value;
    }
}

template<typename T>
Vector<T>::~Vector()
{
    if (p != nullptr) {
        delete[] p;
        p = nullptr;
    }
    cout << "Huy Vector\n";
}

template<typename T>
void Vector<T>::show()
{
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}
