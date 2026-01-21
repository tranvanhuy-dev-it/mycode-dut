#include<iostream>

using namespace std;

void input(float **p, int m, int n) {
    for (int i = 0; i < m; i++) {
        *(p + i) = new float[n];
        for (int j = 0; j < n; j++) {
            cout << "p[" << i << "][" << j << "] = ";
            cin >> *(*(p + i) + j); 
        }
    }
}

void output(float **p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(p + i) + j) << " ";
        } 
        cout << endl;
    }
}

void min_max(float **p, int m, int n)  {
    float min, max;
    for (int i = 0; i < m; i++) {
        min = INT8_MAX;
        max = 0;
        for (int j = 0; j < n; j++) {
            if (*(*(p + i) + j) < min) {
                min = *(*(p + i) + j);
            }
            if (*(*(p + i) + j) > max) {
                max = *(*(p + i) + j);
            }
        }
        cout << "Hang " << i << ":  Min = " << min << ", Max = " << max << endl;
    }
}

void free(float **p, int m, int n) {
    for (int i = 0; i < m; i++) {
        delete[] p[i];
    }
    delete[] p;
}

int main() {

    int n, m;
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
    float **p = new float*[m];
    cout << "\nNhap vao ma tran mxn:\n";
    input(p, m, n);
    cout << "\nMa tran cua ban la:\n";
    output(p, m, n);
    min_max(p, m, n);
    free(p, m, n);
    return 0;
}