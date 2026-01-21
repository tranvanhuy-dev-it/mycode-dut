#include<stdio.h>

int main(){
    
    int sodong, thoigian;
    printf("Nhap tong so dong code: ");
    scanf("%d", &sodong);
    printf("Nhap thoi gian lam viec: ");
    scanf("%d", &thoigian);
    int tienton;
    if (sodong<10){
        tienton=1;
    }
    if (sodong>=10&&sodong<20){
        tienton=2;
    }
    if (sodong>=20){
        tienton=5;
    }
    int tongtien=thoigian*20-tienton;
    printf("Thu nhap cua lap trinh vien nay la: %d$\n", tongtien);
    return 0;
}