#include<stdio.h>
#include<string.h>

int main(){

    char A[10];
    scanf("%s", A);
    int l = strlen(A);

    // Kiểm tra nếu ký tự cuối là dấu chấm và bỏ nó
    if (A[l-1] == '.'){
        A[l-1] = '\0';  // Loại bỏ dấu chấm
        l--;
    }

    int thu = 0;

    // Kiểm tra xem có 4 ký tự liên tiếp giống nhau hay không
    for (int i = 0; i < l - 3; i++) {
        if (A[i] == A[i + 1] && A[i + 1] == A[i + 2] && A[i + 2] == A[i + 3]) {
            thu = 1;  // Đánh dấu nếu tìm thấy tứ quý
            break;
        }
    }

    // In ra kết quả
    if (thu) {
        printf("So tu quy!\n");
    } else {
        printf("Khong la so tu quy!\n");
    }

    return 0;
}
