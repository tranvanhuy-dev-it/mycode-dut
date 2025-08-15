#include <stdio.h>
#include <math.h>

// Hàm kiểm tra một số có phải số nguyên tố không
int timsonguyento(int A) {
    if (A < 2) return -1; // Các số nhỏ hơn 2 không phải là số nguyên tố
    if (A == 2) return 1; // 2 là số nguyên tố
    
    for (int j = 2; j <= sqrt(A); j++) {  // Duyệt từ 2 đến căn bậc hai của A
        if (A % j == 0) {
            return -1;  // Nếu chia hết cho j, không phải số nguyên tố
        }
    }
    return 1;  // Là số nguyên tố
}

int main() {
    int n;
    
    // Nhập kích thước mảng
    scanf("%d", &n);
    int A[n];
    
    // Nhập các phần tử của mảng
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    // Kiểm tra từng phần tử xem có phải số nguyên tố không
    int found = 0;  // Cờ để kiểm tra xem có tìm thấy số nguyên tố hay không
    for (int i = 0; i < n; i++) {
        int x = timsonguyento(A[i]);
        if (x == 1) {
            printf("%d ", A[i]);  // In ra số nguyên tố
            found = 1;  // Đánh dấu đã tìm thấy ít nhất một số nguyên tố
        }
    }
    
    if (!found) {
        printf("NO");  // Nếu không tìm thấy số nguyên tố nào
    }
    
    return 0;
}
