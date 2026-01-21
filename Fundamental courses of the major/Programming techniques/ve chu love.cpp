#include<stdio.h>

int main(){
    
    int n;
    printf("n=");
    scanf("%d", &n);
    printf("\n\n\n");
    printf("=");
    for (int i=1; i<n+1; i++){
        printf(" ");
    }
    for (int i=0; i<n; i++){
        printf("=");
    }
    printf(" =");
    for (int i=0; i<2*n-3; i++){
        printf(" ");
    }
    printf("= ");
    for (int i=0; i<n; i++){
        printf("=");
    }
    printf("\n");
    for(int j=1; j<(n-3)/2+1; j++){
        printf("=");
        for (int i=1; i<n+1; i++){
        printf(" ");
        }
        printf("=");
        for (int i=1; i<n-1; i++){
        printf(" ");
        }
        printf("=");
        for (int i=0; i<j+1; i++){
            printf(" ");
        }
        printf("=");
        for (int i=0; i<2*n-3-2*j; i++){
            printf(" ");
        }
        printf("=");
        for (int i=0; i<j+1; i++){
            printf(" ");
        }
        printf("=");
        for (int i=1; i<n; i++){
        printf(" ");
        }
        printf("\n");
        
    }
    printf("=");
    for (int i=1; i<n+1; i++){
    printf(" ");
    }
    printf("=");
    for (int i=1; i<n-1; i++){
    printf(" ");
        }
    printf("=");
    for (int i=0; i<(n+1)/2; i++){
        printf(" ");
    }
    printf("=");
    for (int i=0; i<n-2; i++){
        printf(" ");
    }
        printf("=");
    for (int i=0; i<(n+1)/2; i++){
        printf(" ");
    }
    for (int i=0; i<n; i++){
        printf("=");
    }
     printf("\n");
    for(int j=(n+1)/2; j<=n-2; j++){
        printf("=");
        for (int i=1; i<n+1; i++){
        printf(" ");
        }
        printf("=");
        for (int i=1; i<n-1; i++){
        printf(" ");
        }
        printf("=");
        for (int i=0; i<j+1; i++){//
            printf(" ");
        }
        printf("=");
        for (int i=0; i<2*n-3-2*j; i++){
            printf(" ");
        }
        printf("=");
        for (int i=0; i<j+1; i++){
            printf(" ");
        }
        printf("=");
        for (int i=1; i<n; i++){
        printf(" ");
        }
        printf("\n");  
    }
    for (int i=0; i<n; i++){
        printf("=");
    }
    printf(" ");
    for (int i=0; i<n; i++){
        printf("=");
    }
    for (int i=0; i<n; i++){
        printf(" ");
    }
    printf("=");
    for (int i=0; i<n; i++){
        printf(" ");
    }
    for (int i=0; i<n; i++){
        printf("=");
    }
    printf("\n\n\n\n");
return 0;
}