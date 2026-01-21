#include<stdio.h>
void quicksoft(int a[], int l, int r){
    int p=a[(r+l)/2];
    int i=r, j=l;
    while(i<j){
        while(a[i]<p){
            i++;
        }
        while(a[j]>p){
            j--;
        }
        if(i<=j){
            int t=a[i];
            a[j]=a[i];
            a[i]=t;
            i++;
            j--;
        }
    }
    if(i<r){
        quicksoft(a, i, r);
    }
    if(l>j){
        quicksoft(a, l, j);
    }
}

int main(){
    int a[11]={-1, 6, 34, 89, 34, 6, 87, 2324, 4546464, -53534}, n=10;
    quicksoft(a, 0, 10);
    for (int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}