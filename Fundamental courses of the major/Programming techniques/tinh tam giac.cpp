#include<stdio.h>
#include<math.h>

int main(){

    printf("Nhap vao kich thuoc ba canh cua tam giac! \n");
    int a, b ,c;
    scanf("%d %d %d", &a, &b, &c);//nhap vao ba canh tam giac

    if ((a+b>c)&&(a+c>b)&&(b+c>a)){
        float ha, hb, hc;
        ha = sqrt((2*(b*b+c*c)-c*c)/4);
        hb = sqrt((2*(a*a+c*c)-b*b)/4);
        hc = sqrt((2*(b*b+a*a)-c*c)/4);
        printf("Do dai ba duong trung tuyen la:\nha=%0.3f\nhb=%0.3f\nhc=%0.3f", ha, hb, hc);
    }

    else printf("Xin loi!\nVui long nhap vao kich thuoc ba canh cua mot tam giac!");//thong bao du lieu nhap vao khong dung

    return 0;
}