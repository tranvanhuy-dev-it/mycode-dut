#include <stdio.h>
#include <math.h>

float HePT[100][100];
float x[100] = {0};
int n;


void inHePT(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n + 1; j++){
			printf("%.2f\t", HePT[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void inkq(){
	for (int i = 1; i <= n; i++){
		printf("x%d = %.3f ",i, x[i]);
	}
	printf("\n");
}

// 10 2 1 10
// 1 10 2 12
// 1 1 10 8

void lapDon(){
	// xu ly du lieu dau vao
	for (int i = 1; i <= n; i++){
		float tam = HePT[i][i];
		for (int j = 1; j <= n + 1; j++){
			HePT[i][j] = HePT[i][j] / tam;
			if (j != n + 1 && i != j) HePT[i][j] *= (-1);
		}
	}
	int ok = 1;
	while(ok){
		ok = 0;
		for (int i = 1; i <= n; i++){ // tính từng biến x. ví dụ x1 x2
			float newX = 0;
			for (int j = 1; j <= n; j++){ // chạy biểu thức của mỗi biến x, ví dụ x1 = 3x2 + 5x3..
				if (i != j) newX += HePT[i][j] * x[j];
			}
			newX += HePT[i][n + 1];
			if (fabs(newX - x[i]) > 0.0001) ok = 1;
			x[i] = newX;
		}
	}
}

int main(){
	double dx[] = {1, 2, 3 ,4, 5};
	double dy[] = {2, 4, 5, 9, 8};
	double sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0, sumY = 0, sumXY = 0, sumX2Y = 0;
	int soLuong = sizeof(dx) / sizeof(dx[0]);
	for (int i = 0; i < soLuong; i++){
		sumX += dx[i];
		sumX2 += (dx[i] * dx[i]);
		sumX3 += (dx[i] * dx[i] * dx[i]);
		sumX4 += (dx[i] * dx[i] * dx[i] * dx[i]);
		sumY += log10(dy[i]);
		sumXY += (dx[i] * log10(dy[i]));
		sumX2Y += (dx[i] * dx[i] * log10(dy[i]));
	}
	n = 2;
	HePT[1][1] = soLuong; HePT[1][2] = sumX;  HePT[1][3] = sumY;
	HePT[2][1] = sumX;    HePT[2][2] = sumX2; HePT[2][3] = sumXY;
	inHePT();
	lapDon();
	printf("%.2lf *x^(%.2lf)", pow(10, x[1]), x[2]);
}