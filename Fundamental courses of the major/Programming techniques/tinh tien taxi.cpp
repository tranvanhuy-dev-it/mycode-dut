#include<stdio.h>

int main(){
    
    float km;
    printf("So km da di la: ");
    scanf("%f", &km);
    int giatien;
    float thanhtien, tongtien;
    if(km<=1){
        giatien=15000;
    }
    else if (km>1&&km<=5){
        giatien=13500;
    }
    else if (km>5){
        giatien=11000;
    }
    thanhtien=giatien*km;
    if (km>120){
        tongtien=thanhtien*90/100;
    }
    else tongtien=thanhtien;
    printf("So tien can phai tra la: %0.1f\n", tongtien);
    return 0;
}