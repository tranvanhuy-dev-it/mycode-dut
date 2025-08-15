#include<bits/stdc++.h>

using namespace std;

int main() {

    long long a, b;
    cin >> a >> b;

    long long sum = 0;
    for (long long i = a; i <= b; ++i) {
        cout << floor(sqrt(i)) << " ";
        sum += sqrt(i);
    }
    cout << sum << "\n"; 

    return 0;
}