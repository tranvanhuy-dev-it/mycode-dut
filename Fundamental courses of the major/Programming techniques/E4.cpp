#include<iostream>

using namespace std;

void calculate(int one, int two, int three, int &max){
    max = one;
    if (two > max){
        max = two;
    }
    if (three > max){
        max = three;
    }
}

int main (){
    int one, two, three, max;
    
    cin >> one >> two >> three;

    calculate(one, two, three, max);

    cout << "Max " << one << ", " << two << ", " << three << ": " << max << endl;
    return 0;
}