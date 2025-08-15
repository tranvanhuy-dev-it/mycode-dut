#include<iostream>
#include<math.h>
using namespace std;

void nhap(int &xa, int &ya, int &xb, int &yb, int &xc, int &yc, int &xm, int &ym){
    cout << "Nhap toa do cac diem:\n";
    cout << "A(xa, ya): ";
    cin >> xa >> ya;
    cout << "B(xb, yb): ";
    cin >> xb >> yb;
    cout << "C(xc, yc): ";
    cin >> xc >> yc;
    cout << "M(xm, ym): ";
    cin >> xm >> ym;
}
void xuly(float s1, float s2, float s3, float s4){
    if(s1==s2+s3+s4){
        if(s1==s2+s3 || s1==s3+s4 || s1==s2+s4){
            cout << "M nam tren canh tam giac ABC\n";
        }
        else{
            cout << "M nam trong tam giac ABC\n";
        }
    }
    else{
        cout << "M nam ngoai tam giac ABC\n";
    }
}
int main(){

    int xa, xb, xc, ya, yb, yc, xm, ym;
    float s1, s2, s3, s4;
    nhap(xa, ya, xb, yb, xc, yc, xm, ym);
    s1=(xa*yb-xb*ya+xb*yc-xc*yb+xc*ya-xa*yc)*0.5;//ABC
    s2=(xa*yb-xb*ya+xb*ym-xm*yb+xm*ya-xa*ym)*0.5;//MAB
    s3=(xm*yb-xb*ym+xb*yc-xc*yb+xc*ym-xm*yc)*0.5;//MBC
    s4=(xa*ym-xm*ya+xm*yc-xc*ym+xc*ya-xa*yc)*0.5;//MAC
    xuly(s1, s2, s3, s4);
    return 0;
}