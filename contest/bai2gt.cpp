#include <iostream>
using namespace std;    

int DayConLonNhat(int A[], int n)
{
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++) dp[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else 
        {
            dp[i] = dp[i - 1];
        }
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    int A[1000];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << DayConLonNhat(A, n) << endl;
    return 0;
}