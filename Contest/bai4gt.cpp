#include <iostream>
using namespace std;

int s[1000];
int a[1000];

int SumS(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += 3.14 * A[i] * A[i];
    }
    return sum;
}

int Hinhtron(int k, int D)
{
    if (SumS(s, k) <= D)
    {
        for (int i = 0; i < k; i++)
        {
            cout << s[i] << " ";
        }
    }
    else 
    {
        for (int i = 1; i <= D; i++)
        {
            s[k] = a[i];
            if (TrienVong(s, k))
            {
                Hinhtron(k + 1, D);
            }
        }
    }
}

bool TrienVong(int A[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (A[i] == A[n-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int D;
    cin >> D;
    for (int i = 1; i <= D; i++)
    {
        a[i] = i;
    }
    return 0;
}