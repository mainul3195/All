#include<stdio.h>
int main()
{
	int ar[100003],n,i,j,q,a,b,t;
	ar[0]=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &j);
		ar[i]=j+ar[i-1];
	}
	scanf("%d", &q);
	for(i=0; i<q; i++)
	{
		scanf("%d %d", &a, &b);
		if(a>b)
			a^=b^=a^=b;
		printf("%d\n", ar[b+1]-ar[a]);
	}
	return 0;
}