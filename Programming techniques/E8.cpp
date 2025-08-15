#include <iostream>

using namespace std;

bool xuly(int year){
        if ( year % 4 == 0){
            if (year % 100 == 0){
                if ( year % 400 == 0){
                    return true;
                }
            }
            return false;
        }
        return false;
    }

int main(){
    int year, month;
    cin >> year >> month;
    if (xuly(year)){
        if (month == 2){
            cout << "Thang "<<month<<" nam "<<year<<" co "<< 29 <<" ngay.";
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8  || month == 10 || month == 12){
            cout << "Thang "<<month<<" nam "<<year<<" co "<< 31 <<" ngay.";
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11){
            cout << "Thang "<<month<<" nam "<<year<<" co "<< 30 <<" ngay.";
        }
    }
    else {
        if (month ==2){
            cout << "Thang "<<month<<" nam "<<year<<" co "<< 28 <<" ngay.";
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8  || month == 10 || month == 12){
            cout << "Thang "<<month<<" nam "<<year<<" co "<< 31 <<" ngay.";
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11){
            cout << "Thang "<<month<<" nam "<<year<<" co "<< 30 <<" ngay.";
        }
    } 
    return 0;
}