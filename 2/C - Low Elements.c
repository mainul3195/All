#include<stdio.h>
int main()
{
	int n, d, count=0, min = 300000;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &d);
		if(d<min)
		{
			min = d;
			count++;
		}

	}
	printf("%d\n", count);
	return 0;
}