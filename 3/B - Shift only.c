#include<stdio.h>
int main()
{
	int n, a[201], i, j, flag;
	while(~scanf("%d", &n))
	{
		for(i=0; i<n; i++)
			scanf("%d", a+i);
		j=0;
		flag = 0;
		while(++j)
		{
			for(i=0; i<n; i++)
			{
				if(a[i]%2)
				{
					flag = 1;
					break;
				}		
				a[i]/=2;		
			}
			if(flag) break;
		}
		printf("%d\n", --j);
	}
	return 0;
}