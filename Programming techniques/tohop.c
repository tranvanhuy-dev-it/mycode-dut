#include <stdio.h>
#include<math.h>

long xuly(int k, int n){
    long gt=1;

    if(k==0 || k==n){
        return 1;
    } else{
        for(int i=1; i<=k; i++) {
            gt=gt*(n-i+1)/i;
        }
    }

    return gt;
}

int main() {
    int k, n;
    scanf("%d%d", &k, &n);
    long gt=xuly(k, n);
    printf("%ld\n", gt);
    return 0;
}
