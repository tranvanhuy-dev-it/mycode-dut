#include <stdio.h>

void nhap(int n, float A[10][10]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%f", &A[i][j]);
        }
    }
}

void xuat(int n, float A[10][10]){
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int matrannghichdao(int n, float A[10][10], float B[10][10]) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) {
                B[i][j]=1.0;
            } 
            else {
                B[i][j]=0.0;
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (A[i][i] == 0) {
        //phần tử chéo chính là 0, hoán đổi hàng
            int found=0;
            for (int j=i+1; j<n; j++){
                if (A[j][i]!=0) {
                    for (int k=0; k<n; k++){
                        float t=A[i][k];
                        A[i][k]=A[j][k];
                        A[j][k]=t;

                        t=B[i][k];
                        B[i][k]=B[j][k];
                        B[j][k]=t;
                    }
                    found=1;
                    break;
                }
            }

            //không tìm được hàng để hoán đổi thì ma trận không khả nghịch
            if (!found){
                return 0;
            }
        }
        float p=A[i][i];
        for (int j=0; j<n; j++) {
            A[i][j]/=p;
            B[i][j]/=p;
        }
        for (int k = 0; k<n; k++) {
            if (k!=i) {
                float f=A[k][i];
                for (int j=0; j<n; j++) {
                    A[k][j]-=A[i][j] * f;
                    B[k][j]-=B[i][j] * f;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n;
    float A[10][10], B[10][10];
    scanf("%d", &n);
    nhap(n, A);
    xuat(n, A);
    if (matrannghichdao(n, A, B)) {
        xuat(n, B);
    } 
    else {
        printf("Ma tran khong kha nghich!\n");
    }

    return 0;
}
