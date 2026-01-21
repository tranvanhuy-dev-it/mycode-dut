#include<stdio.h>

int main(){
    
    float diem;
    printf("Nhap vao diem cua hoc sinh: ");
    scanf("%f", &diem);
    int yeu=diem<4.0;
    int trungbinh=diem>=4.0&&diem<5.5;
    int kha=diem>=5.5&&diem<8.0;
    int gioi=diem>=8.0&&diem<9.0;
    int xuatsac=diem>=9.0;
    if(yeu){
       printf("Hoc sinh xep loai: Yeu\n");
    }
    else if(trungbinh){
       printf("Hoc sinh xep loai: Trung binh\n");
    }
    else if(kha){
       printf("Hoc sinh xep loai: Kha\n");
    }
    else if(gioi){
       printf("Hoc sinh xep loai: Gioi\n");
    }
    else if(xuatsac){
       printf("Hoc sinh xep loai: Xuat sac\n");
    }
    return 0;
}