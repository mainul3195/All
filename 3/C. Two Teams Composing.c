#include<stdio.h>
int main()
{
	int t, a,n,i,samemax,final,differentmax,same;
	char s[200002];
	scanf("%d", &t);
	while(t--)
	{
		for(i=1; i<200002; i++)
			s[i]=0;
		samemax=differentmax=0;
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &a);
			s[a]++;
			if(s[a]==1)
				differentmax++;
			else if(s[a]>1)
			{
				samemax=s[a];
				same = a;
			}
		}
		if(differentmax==samemax)
			final = differentmax-1;
		else if(differentmax > 1 && samemax ==0)
			final = 1;
		else
			final = differentmax > samemax ? samemax : differentmax;
		printf("%d\n", final);
	}
	return 0;
}