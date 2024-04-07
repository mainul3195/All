#include<stdio.h>
int main()
{
	int t,n,m,k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		if(m<=n/k)
		printf("%d\n", m);
		else printf("%d\n", n/k-((m-n/k)+k-2)/(k-1));
	}
	return 0;
}