//Giả sử lãi suất hằng tháng là d=2%, tiền vay ngân hàng là T = 1000000. Viết 
//chương trình nhập số nguyên dương n và in ra số tiền phải trả sau n tháng
#include<stdio.h>

int main(){
    
    int k, n;
    float T=1000000;
    printf("n= "); 
    scanf("%d", &n);
    for (k=0; k<n; k++) T*=1.02;
    printf("So tien phai tra = %0.2f\n", T);
    return 0;
    return 0;
}