#include<stdio.h>
int min(int a, int b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	int n,x,m,a[101], i, c1,c2, st;
	while(~scanf("%d %d %d", &n, &m, &x))
	{
		c1=c2=0;
		for(i=0; i<m; i++)
		{
			scanf("%d", &st);
			if(st<x) c1++;
			else if(st>x) c2++;
		}
		printf("%d\n", min(c2,c1));
	}
	return 0;
}