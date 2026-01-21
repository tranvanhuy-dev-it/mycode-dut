#include<stdio.h>
#include<math.h>

int giaithua(int n);
float tinh(int x);

int main(){

    int x;
    printf("Nhap gia tri can tinh: "); scanf("%d", &x);
    printf("Gia tri cua ham so la: e^%d = %.2f\n", x, tinh(x));
    return 0;
}

int giaithua(int n){
    int i, temp=1;
    for(i=1; i<=n; i++){
        temp*=i;
    }
    return temp;
}

float tinh(int x){
    float E=0.000000001, s=1;
    int i=1;
    do{
        float temp=pow(x, i)/giaithua(i);
        s+=temp;
        i++;
    }
    while(pow(x, i)/giaithua(i)>E);
    return s;
}