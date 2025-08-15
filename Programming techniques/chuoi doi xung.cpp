#include <stdio.h>
#include <string.h>

void daochuoi(int l, char A[], char B[]){
    for (int i=0; i<l; i++){
        B[l-i-1]=A[i];  
    }
    B[l]='\0';
}
int chuoidoixung(int l, char A[], char B[]){
    for (int i=0; i<l; i++){
        if(A[i]!=B[i]){
            return 0;
        }
    }
    return 1;
}


int main() {
    char A[21], B[21];
    scanf("%20s", A);
    int l=strlen(A);
    daochuoi(l, A, B);

    if (chuoidoixung(l, A, B)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
