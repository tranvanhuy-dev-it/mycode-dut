#include<stdio.h>
void nhap(int a[], int n){
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
}
void xuat(int a[], int n){
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}
void quicksoft(int a[], int l, int r){
    int p=a[(l+r)/2];
    int i=l, j=r;
    while (i<j){
        while (a[i]<p){
            i++;
        }
        while (a[j]>p){
            j--;
        }
        if (i<=j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }
    if (i<r){
        quicksoft(a, i, r);
    }
    if (l<j){
        quicksoft(a, l, j);
    }
}
int main(){
    int a[10000], n;
    scanf("%d", &n);
    nhap(a, n);
    xuat(a, n);
    printf("\n");
    quicksoft(a, 0, n-1);
    xuat(a, n);
    return 0;
}