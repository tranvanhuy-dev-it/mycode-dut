#include<stdio.h>

int main(){
   int m, n;
   scanf("%d %d", &m, &n);
   
   if (m <= 1 && n <= 1) {
      printf("%d va %d chua hop le!\n", m, n);
   } 

   else if ((m >= 2 && n >= 2) || (m==1 && n!=1) || ( n==1 && m!=1)) {
      int k = m * n;
      int i;
      if (k % 2 == 0) {
         i = k / 2;
      } 
      else {
         i = (k - 1) / 2;
      }
      printf("%d\n", i);
   }

   return 0;
}
