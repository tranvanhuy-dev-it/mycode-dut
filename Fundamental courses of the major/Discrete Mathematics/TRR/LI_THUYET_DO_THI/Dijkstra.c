#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soDinh, soCanh;
int visited[100] = {0};
int a[100][100];

typedef struct chiSoDinh
{
	int val, parent;
}chiSoDinh;


void khoiTao(chiSoDinh a[]){
	for (int i = 1; i <= soDinh; i++){
		a[i].val = 9999;
	}
	a[1].val = 0;
}

int main(){
	printf("Nhap so dinh va canh: ");
	scanf("%d %d", &soDinh, &soCanh);

	chiSoDinh tapDinh[100];
	int soDinhConLai = soDinh;
	khoiTao(tapDinh);
	int dinh1, dinh2, trongSo;
	for (int i = 1; i <= soCanh; i++){
		scanf("%d %d %d", &dinh1, &dinh2, &trongSo);
		a[dinh1][dinh2] = trongSo;
		// a[dinh2][dinh1] = trongSo;
	}

	int x = 1;
	
	
	
	while(soDinhConLai){
		int gtMin = 99999;
		int chiSoMin = 99999;
		visited[x] = 1;
		soDinhConLai--;
		for (int i = 1; i <= soDinh; i++){
			if (!visited[i] && a[x][i] > 0 && tapDinh[x].val + a[x][i] < tapDinh[i].val){
				tapDinh[i].val = tapDinh[x].val + a[x][i];
				tapDinh[i].parent = x;
			}
		}

		for (int i = 1; i <= soDinh; i++){
			if (!visited[i] && tapDinh[i].val < gtMin){
				gtMin = tapDinh[i].val;
				chiSoMin = i;
			}
		}
		x = chiSoMin;
	}

	for (int i = 2; i <= soDinh; i++){
		printf("%d -> ", i);
		int tam = tapDinh[i].parent;
		int trongSoTam = tapDinh[i].val;
		while (tam != 1){
			printf("%d -> ", tam);
			tam = tapDinh[tam].parent;
		}
		printf("1 (%d)\n", trongSoTam);
	}





}
// 5 7
// 1 2 2
// 1 3 5
// 2 3 1
// 2 4 3
// 3 4 2
// 3 5 7
// 4 5 4

// 5 7
// 1 2 2
// 1 3 5
// 2 3 1
// 2 4 3
// 3 4 1
// 3 5 7
// 4 5 4


