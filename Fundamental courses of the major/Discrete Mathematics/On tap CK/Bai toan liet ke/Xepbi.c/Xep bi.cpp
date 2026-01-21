#include <iostream>
#include <string.h>
using namespace std;

void printArray(int a[], int k) {
    for(int i = 0; i < 3 * k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int i, int k, int a[], int cnt[], int &res) {
    for(int j = 1; j <= 3; j++){
        if((a[i - 1] != j && cnt[j] != k)|| i == 0){
            a[i] = j;
            cnt[j]++;
            if(i == 3*k - 1 && cnt[1] == k && cnt[2] == k && cnt[3] == k){
                res++;
                printArray(a, k);
            } else {
                Try(i + 1, k, a, cnt, res);
            }
            cnt[j]--;
        }
    }
}


int main(){
    int k; cin >> k;
    int a[3 * k], cnt[k + 1];
    memset(cnt, 0, sizeof(cnt));
    int res = 0;
    Try(0, k, a, cnt, res);
    cout << res << endl;
    return 0;
}