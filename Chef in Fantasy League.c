#include<stdio.h>
int price[101];
int player[101];
int main()
{
	int t,s,i,n;
	scanf("%d", &t);
	while(t--)
	{
		int fmin=101,dmin=101;
		scanf("%d %d", &n, &s);
		for(i=0; i<n; i++)
			scanf("%d", price+i);
		for(i=0; i<n; i++)
			scanf("%d", player+i);
		for(i=0; i<n; i++)
		{
			if(player[i]==0)
			{
				if(price[i]<dmin)
					dmin=price[i];
			}
			else
				if(price[i]<fmin)
					fmin=price[i];
		}
		if((dmin+fmin)<=(100-s))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}