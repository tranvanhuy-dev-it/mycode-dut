#include<stdio.h>
#include<math.h>

double Find_m(double n, double a[]);
double Find_a(double n, double a[]);

int main(){

    double n, a[100];
    printf("Bac cua phuog trinh n= "); scanf("%lf", &n);
    for(int i=0; i<=n; i++){
        printf("a[%d]= ", i); scanf("%lf", &a[i]);
    }
    double m=Find_m(n, a);
    double A=Find_a(n, a);
    printf("Can tren cua nghiem duong phuong trinh dai so la: %.lf\n", 1 + pow(A / a[0], 1/m));
    return 0;
}

double Find_m(double n, double a[]){
    double m;
    for(int i=0; i<=n; i++){
        if(a[i]<0){
            m=i;
            break;
        }
    }
    return m;
}

double Find_a(double n, double a[]){
    double max=0;
    for (int i=0; i<=n; i++){
        if(a[i] < 0 && abs(a[i]) > max){
            max = abs(a[i]);
        }
    }
    return max;
}