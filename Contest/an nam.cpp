#include <iostream>
#include <algorithm>
using namespace std;

int A[5][5]; 
int dp[5][5]; 

int main() {
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            cin >> A[i][j];

    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (i == 1 && j == 1) {
                dp[i][j] = A[i][j];
            } else {
                int from_top = 0, from_left = 0;

                if (i > 1) {
                    from_top = dp[i - 1][j];
                }

                if (j > 1) {
                    from_left = dp[i][j - 1];
                }

                dp[i][j] = A[i][j] + max(from_top, from_left);
            }
        }
    }

    cout << dp[4][4] << endl; 
    return 0;
}
