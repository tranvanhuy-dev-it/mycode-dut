#include<stdio.h>
#include<math.h>

int giaithua(int n);
float tinh(int x);

int main(){

    int x;
    printf("Nhap gia tri can tinh: "); scanf("%d", &x);
    printf("Gia tri cua ham so la: %.2f\n", tinh(x));
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
        float t=(pow(x, 2*i)*pow(-1, i))/giaithua(2*i);
        s+=t;
        i+=1;
    }
    while(pow(x, 2*i)/giaithua(2*i)>E);
    return s;
}