#include<iostream>

using namespace std;

int main(){

    int SIN, check_digit, so, s1=0, s2=0;
    while(1>0){
        cout << "SIN(chon 0 de thoat): ";
        cin >> SIN;
        if(SIN==0){
            break;
        }
        check_digit = SIN % 10;
        SIN = SIN / 10;
        for (int i=1; i<=8; i++){
            so = SIN % 10;
            SIN = SIN /10;
            if(i % 2 == 0){
                s1 += so;
            }
            else{
                so *= 2;
                if(so / 10 != 0){
                    int du = so % 10;
                    so = so /10;
                    s2 = s2 + so + du;
                }
                else{
                    s2 += so;
                }
            }
        }
        int sum = check_digit + s1 + s2;
        if(sum%10==0){
            cout << "Ma so SIN hop le!\n";
        }
        else{
            cout << "Ma so SIN khong hop le!\n";
        }
    }
    return 0;
}