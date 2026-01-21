 #include<stdio.h>
 
 int main(){
 	
 	int x, y, z, min, max;
 	
 	
 	scanf("%d %d %d", &x, &y, &z);
 	
 	min = x;
 	if (y<min)
 		min=y;
	if (z<min)
 		min=z;
 	
 	
 	printf("%d", min);
 	return 0;
 }

