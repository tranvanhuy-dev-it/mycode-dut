#include<stdio.h>

void quicksort(int a[], int l, int r){
    int p=a[(r+l)/2];
    int i=l, j=r;
    while(i<=j){
        while(a[i]<p){
            i++;
        }
        while(p<a[j]){
            j--;
        }
        if(i<=j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }
    if(l<j){
        quicksort(a, l, j);
    }
    if(i<r){
        quicksort(a, i, r);
    }
}
int main(){
    int N, m, a[100001];
    scanf("%d %d", &N, &m);
    for(int i=0; i<m; i++){
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, m-1);
    int dem=0, s=0;
    for(int i=0; i<m; i++){
        s+=a[i];
        if(s>N){
            break;
        }
        dem++;
    }
    printf("%d\n", dem);
    return 0;
}