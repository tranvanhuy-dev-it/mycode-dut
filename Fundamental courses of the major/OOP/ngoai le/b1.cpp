#include <iostream>
#include "MyExp.h"
using namespace std;

int main()
{

    int a, b;
    do
    {
        cout << "a: "; cin >> a;
        cout << "b: "; cin >> b;
        try
        {
            if (b == 0)
                throw MyExp("Ngu vua vua");
            else
                cout << "c = a / b =  " << a / b << endl;;
        }
        catch (const int &e)
        {
            cout << "int: " << e << endl;
        }
        catch (const double &e)
        {
            cout << "double: " << e << endl;
        }
        catch (const MyExp &e)
        {
            cout << "MyExp: " << e << endl;
        }
        catch (const Exp &e)
        {
            cout << "Exp: " << e << endl;
        }
        catch (...)
        {
            cout << "Bo bat duoc roi " << endl;
        }
    } while (b != 0);

    return 0;
}