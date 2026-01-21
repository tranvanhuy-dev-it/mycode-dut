#include <iostream>
#include "MyExp.h"
using namespace std;

int B(const int& a, const int& b)
{
    try
    {
        if (b == 0)
            throw Exp("Dot lam thang dan");
    }
    catch(const MyExp& e)
    {
        cout << "B: " << e << endl;
        throw;
    }

    catch(const Exp& e)
    {
        cout << "B: " << e << endl;
        throw e;
    }
    return a  / b;
}

void A(const int &a, const int & b)
{
    try
    {
        cout << B(a, b) << endl;
    }
    catch(const MyExp& e)
    {
        cout << "A: " << e << endl;
        throw;
    }

    catch(const Exp& e)
    {
        cout << "A: " << e << endl;
        throw;
    }
}

int main()
{

    int a = 3, b = 0;
    try
    {
        A(a, b);
    }
    catch(const MyExp& e)
    {
        cout << "A: " << e << endl;
    }

    catch(const Exp& e)
    {
        cout << "Main: " << e << endl;
    }
    
    return 0;
}