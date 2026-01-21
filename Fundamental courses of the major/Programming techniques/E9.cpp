#include<iostream>
#include<cmath>

using namespace std;

int a, b, c, delta;

int main(){
    cin >> a >> b >> c;
    delta = b*b - 4*a*c;
    if (delta < 0){
        cout << "Phuong trinh vo nghiem!";
    }
    if (delta==0){
        int x = -b/(2*a);
        cout << "x="<<x;
    }
    else if (delta>0){
        int x1=(-b+sqrt(delta))/(2*a);
        int x2=(-b-sqrt(delta))/(2*a);
        cout << x1 << "endl"<< x2;
    }
    return 0;
}