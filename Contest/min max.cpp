#include<iostream>
#include<limits>
using namespace std;

int main () {

    int n, A[10000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int min = INT_FAST16_MAX;
    int max = INT_FAST16_MIN;

    for (int i = 0; i < n; i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }

    cout << max << " " << min << "\n";
    return 0;


}