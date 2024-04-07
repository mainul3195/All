#include<stdio.h>
int main()
{
	long long a[60];
	int i;
	a[0]=0;
	a[1]=1;
	for(i=2; i<55; i++)
		a[i]=a[i-1]+a[i-2];
	int j=-1,n;
	scanf("%d", &n);
	while(a[++j]!=n);
	if(j==0) printf("0 0 0");
	else if(j==1) printf("0 0 1");
	else if(j==3) printf("0 1 1");
	else printf("%lld %lld %lld", a[j-4], a[j-3], a[j-1]);
	return 0;
}