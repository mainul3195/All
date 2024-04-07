#include<stdio.h>
int main()
{
	int t,i,j,x,n, oddcount, evencount;
	scanf("%d", &t);
	while(t--)
	{
		oddcount=0, evencount=0;
		scanf("%d %d", &n, &x);
		for(i=0; i<n; i++)
		{
			scanf("%d", &j);
			if(j%2) oddcount++;
			else evencount++;
		}
		if(evencount==n || oddcount==n&&x%2==0 || x==n&&oddcount%2==0)
			printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}