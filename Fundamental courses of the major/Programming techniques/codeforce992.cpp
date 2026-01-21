#include<iostream>

using namespace std;

int xuly(int A[100], int n, int k){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if((A[i]-A[j])%k!=0 && i!=j){
                return i+1;
            }
        }
    }
    return -1;
}

int main(){
    int t, n, k, i;
    cin >> t;
    int A[100];
    while(t--){
        cin >> n >> k;
        for (int i=0; i<n; i++){
            cin >> A[i];
        }
    int m=xuly(A, n, k);
    
    if(m!=-1){
        cout<<"YES\n"<<m<<"\n";
    }
    else{
        cout<<"NO\n";
    }
    }
    return 0;
}