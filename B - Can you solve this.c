#include<stdio.h>
int main()
{
	int b[30],n,m, a,c,sum,i,cnt;
	while(~scanf("%d %d %d", &n, &m, &c))
	{
		cnt=0;
		for(i=0; i<m; i++)
			scanf("%d", b+i);
		while(n--)
		{
			sum = c;
			for(i=0; i<m; i++)
			{
				scanf("%d", &a);
				sum += b[i]*a;
			}
			if(sum>0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}