#include<stdio.h>
int main()
{
	int t,n,i,cnt,lm;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n%4!=0)
			printf("NO\n");
		else
			{
				printf("YES\n");
				for(i=2;i<=n;i+=2)
					printf("%d ", i);
				for(i=1;i<n-1;i+=2)
					printf("%d ", i);
				i+=(n/4)*2;
				printf("%d\n", i);

			}
	}

	return 0;
}