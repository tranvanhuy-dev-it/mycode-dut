#include<iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a>b){
        int t=b;
        b=a;
        a=t;
    }
    if(b>c){
        int t=b;
        b=c;
        c=t;
    }
    if(a>b){
        int t=b;
        b=a;
        a=t;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}