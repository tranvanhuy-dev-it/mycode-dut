#include<iostream>

using namespace std;

bool xuly(int year){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return true;
    }
    return false;
}
int main(){
    int year;
    cin >> year;
    if(xuly(year)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}