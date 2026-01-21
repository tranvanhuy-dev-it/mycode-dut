#include<stdio.h>
#include<math.h>

int main(){
    long m, n, k;
    scanf("%ld%ld%ld", &m, &n, &k);
    double mu=pow(m, n);
    double du=fmod(mu, k);
    printf("%.f\n", du);
    return 0;
}