#include<stdio.h>

int main(){
    
    int n, k;
    scanf("%d%d", &k, &n);
    float ngt=1, nt1gt=1, kgt=1;
    for (int i=1; i<=n; i++){
        ngt*=i;
    }
    for (int i=1; i<=k; i++){
        kgt*=i;
    }
    for (int i=1; i<=n-k; i++){
        nt1gt*=i;
    }
    float tohop=(ngt*(1.0/(kgt*nt1gt)));
    printf("%.f", tohop);
    return 0;
}