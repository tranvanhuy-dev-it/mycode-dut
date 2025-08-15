#include <iostream>
using namespace std;

char C[] = {'a', 'b', 'c', 'd', 'e'};
int used[10] = {0};
char res[10];
int n;

void printRes() {
    for (int i = 0; i < n; i++) {
        cout << res[i] <<" ";
    }
    cout << endl;
}

void Try(int i) {
    for (int j = 0; j < n; j++) {
        if (used[j] == 0) {
            res[i] = C[j];
            used[j] = 1;
            if (i == n - 1) {
                printRes();
            } else {
                Try(i + 1);
            }
            used[j] = 0;
        }
    }
}

int main() {
    cin >> n;
    Try(0);
    return 0;
}
