#include<float.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

long long n, k, a[1000001];
int hu(const void* c, const void* d) {
      
    return (*(int*)c - *(int*)d);
}
int main(){
	long long sum=0;
    scanf("%lld %lld", &n, &k);
    for (int i=0;i<n;i++) scanf("%lld", &a[i]);
    
    qsort(a,n,sizeof(long long),hu);
    for (int i=0;i<k;i++) sum+=a[i];
    printf("%lld",sum);
    
}
