#include<stdio.h>
int main()
{
	int a, out[100002], n,i;
	while(~scanf("%d", &n))
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d", &a);
			out[a]=i;
		}
		for(i=1; i<=n; i++)
			printf("%d ", out[i]);
	}
	return 0;
}