#include <stdio.h>

int main() {
    int n;

    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);
    
    int A[n]; 

    printf("\nNhap vao mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int dem = 0;
    int s = 0;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (A[i] % 2 == 0) { 
                s += A[i];
                dem++;
            }
        }
    }

    if (dem > 0) {
        float tb = (float)s / dem;
        printf("Gia tri trung binh cua cac phan tu chan tai vi tri chan la: %.4f\n", tb);
    } else {
        printf("Khong co phan tu chan tai vi tri chan.\n");
    }

    return 0;
}
