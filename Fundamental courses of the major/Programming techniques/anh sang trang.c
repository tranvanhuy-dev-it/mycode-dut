#include<stdio.h>
#include<string.h>

int main(){
    int den, d, kq=1e9;
    char a[200001];
    char mau[3]={'R','G','B'};
    scanf("%d%d",& den, &d);
    scanf("%s",a);
    for(int t=0; t<3; t++){
        int sai=0;
        for(int i=0; i<d; i++){
            if(a[i]!=mau[(i+t)%3]){
                sai++;
            }
        }
        if(sai<kq) {
            kq=sai;
        }
        for(int i=d; i<den; i++){
            if(a[i-d] != mau[(i-d+t)%3]){
                sai--;
            }
            if(a[i]!=mau[(i+t)%3]){
                sai++;
            }
            if(sai<kq){
                kq=sai;
            }
        }
    }
    printf("%d\n",kq);
    return 0;
}
