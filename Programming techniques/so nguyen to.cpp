#include<stdio.h>
#include <math.h>

bool songuyento(int n){
if (n<=1){
    return false;
}
if (n==2){
    return true;
}
if (n>=3){
   for (int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
}
return true;
}
int main(){
    int n;
    scanf("%d", &n);
    if (songuyento(n)==true){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}