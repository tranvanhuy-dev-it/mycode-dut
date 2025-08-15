#include<stdio.h>
#include<math.h>

int main(){

    int n;
    scanf("%d", &n);
    float s=1000000*pow(1.02, n);
    printf("%.f\n", s);
    return 0;
}