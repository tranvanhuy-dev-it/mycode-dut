#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string ketqua(int nguoichon, int maychon) {
    if (nguoichon == maychon) {
        return "Hoa!";
    } else if ((nguoichon == 1 && maychon == 3) || // Kéo thắng Bao
               (nguoichon == 2 && maychon == 1) || // Búa thắng Kéo
               (nguoichon == 3 && maychon == 2)) { // Bao thắng Búa
        return "Ban thang!";
    } else {
        return "Ban thua!";
    }
}

int main() {
    srand(time(0));

    int nguoichon;
    int maychon;

    while (true) {
        cout << "\nOan tu ti - Lua chon cua ban:" << endl;
        cout << "1. Keo" << endl;
        cout << "2. Bua" << endl;
        cout << "3. Bao" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap lua chon (1-4): ";
        cin >> nguoichon;
        if (maychon == 4) {
            cout << "Tam biet!\n";
            break;
        }
        if (nguoichon < 1 || nguoichon > 4) {
            cout << "Lua chon khong hop le, vui long thu lai.\n";
            continue;
        }
        maychon = rand() % 3 + 1;
        cout << "Ban chon: " << (nguoichon == 1 ? "Keo" : nguoichon == 2 ? "Bua" : "Bao") << endl;
        cout << "May tinh chon: " << (maychon == 1 ? "Keo" : maychon == 2 ? "Bua" : "Bao") << endl;
        cout << ketqua(nguoichon, maychon) << "\n";
    }

    return 0;
}
