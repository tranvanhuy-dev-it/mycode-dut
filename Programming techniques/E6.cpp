#include<iostream>
#include <string>

using namespace std;
    string n;
    int l;

int main(){
    cin >> n;
    l = n.size();
    if (l<3){
        cout << 0;
    }
    else if (l>=3){
        cout << n[l-3];
    }
    return 0;
}