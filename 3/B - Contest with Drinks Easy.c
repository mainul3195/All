#include<stdio.h>
int main()
{
	int n, t[102]={0}, m, p, x, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &m);
		t[i]=t[i-1]+m;
	}
	scanf("%d", &m);
	for(i=1; i<=m; i++)
	{
		scanf("%d %d", &p, &x);
		printf("%d\n", t[n]-t[p]+t[p-1]+x);
	}
	return 0;
}