#include<stdio.h>
#include<string.h>

int main(){

    char A[1000];
    int s2=0, s3=0, s5=0, s7=0;
    scanf("%s", A);
    int l=strlen(A);
    for (int i=0; i<l; i++){
        if(A[i]=='2'){
            s2++;
        }
        else if(A[i]=='3'){
            s3++;
        }
        else if(A[i]=='5'){
            s5++;
        }
        else if(A[i]=='7'){
            s7++;
        }
    }
    printf("%d\n%d\n%d\n%d\n", s2, s3, s5, s7);
    return 0;
}