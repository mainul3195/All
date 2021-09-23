#include<stdio.h>
int main()
{
	int i,n,a[100002]={0},k,q,t;
	scanf("%d %d %d", &n, &k, &q);
	for(i=0; i<q; i++)
	{
		scanf("%d", &t);
		a[t]++;
	}
	for(i=1; i<=n; i++)
	{
		if(k-q+a[i]>0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}