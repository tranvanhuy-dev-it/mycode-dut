#include<iostream>

using namespace std;
int n, s;
void calculate(int &n, int &s){
    s = n + ( 10 * n + n)+ (100 * n + 10 * n + n);
}

int main(){
    cin >> n;
    calculate( n, s);
    cout << s;
    return 0;
}