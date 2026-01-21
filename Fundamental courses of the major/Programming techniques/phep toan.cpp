#include<stdio.h>

int main() {
    int numberOne, numberTwo;
    char math;
    scanf("%d %d %c", &numberOne, &numberTwo, &math);
    
    if (math != '/' && math != '+' && math != '*' && math != '-') {
        printf("Khong thuc hien duoc, phep tinh khong hop le!\n");
    } else if (math == '/') {
        if (numberTwo != 0) {
            printf("%d / %d = %d\n", numberOne, numberTwo, numberOne / numberTwo);
        } else {
            printf("Khong the chia cho 0!\n");
        }
    } else if (math == '*') {
        printf("%d * %d = %d\n", numberOne, numberTwo, numberOne * numberTwo);
    } else if (math == '-') {
        printf("%d - %d = %d\n", numberOne, numberTwo, numberOne - numberTwo);
    } else if (math == '+') {
        printf("%d + %d = %d\n", numberOne, numberTwo, numberOne + numberTwo);
    }
    
    return 0;
}
