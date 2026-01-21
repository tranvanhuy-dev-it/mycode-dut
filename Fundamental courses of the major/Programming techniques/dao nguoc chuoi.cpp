#include<stdio.h>
#include<string.h>

int main(){

    char chuoi[100];
    char chuoidaonguoc[100];

    printf("Nhap vao chuoi can dao nguoc! \n");
    fgets(chuoi, sizeof(chuoi), stdin);

    int chieudai = strlen(chuoi);

    for (int i=0; i<chieudai; i++){
        chuoidaonguoc[chieudai-i-1]=chuoi[i];
    }
    chuoidaonguoc[chieudai] = '\0';
    printf("Chuoi dao nguoc la: %s\n", chuoidaonguoc);
    return 0;
}