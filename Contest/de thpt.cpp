#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_csc(int a, int b, int c) {
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    return v[1] - v[0] == v[2] - v[1];
}

int main() {
    vector<int> S = {21, 22, 23, 24, 25, 26, 27, 28, 29};
    int valid_count = 0;
    int total_count = 0;

    vector<bool> choose(9, false);
    fill(choose.begin(), choose.begin() + 6, true);
    do {
        vector<int> selected;
        for (int i = 0; i < 9; ++i)
            if (choose[i]) selected.push_back(S[i]);

        sort(selected.begin(), selected.end());
        do {
            int A = selected[0];
            int B = selected[1];
            int C = selected[2];
            int M = selected[3];
            int N = selected[4];
            int P = selected[5];

            if (check_csc(A, M, B) &&
                check_csc(B, N, C) &&
                check_csc(C, P, A)) {
                valid_count++;
            }

            total_count++;
        } while (next_permutation(selected.begin(), selected.end()));

    } while (prev_permutation(choose.begin(), choose.end()));

    cout << valid_count << " " << total_count << endl;

    if (valid_count > 0) {
        int a = (2 * total_count) / valid_count;
        cout << a << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
