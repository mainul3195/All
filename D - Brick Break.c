#include<stdio.h>
int main()
{
	int n, i, j=1,d, count = 0;;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &d);
		if(d==j)
		{
			j++;
			continue;
		}
		count++;
	}
	if(count == n)
		printf("-1\n");
	else printf("%d\n", count);
	return 0;
}