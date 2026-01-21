#include<iostream>
using namespace std;
int s = 0;
void TongLe(int A[], int l, int r)
{
    if (l == r)
    {
        if (A[l] % 2 == 1)
            s += A[l];
    }
    else 
    {
        int m = (l + r) / 2;   
        TongLe(A, l, m);
        TongLe(A, m + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int A[1000];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    TongLe(A, 0, n - 1);
    cout << s << endl;
    return 0;
}