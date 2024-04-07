#include<stdio.h>
int main()
{
	int n, a, b, sum, i;
	while(~scanf("%d %d", &n, &a))
	{
		sum = a;
		for(i=1; i<n-1; i++)
		{
			scanf("%d", &b);
			if(b<a) sum+=b;
			else sum += a;
			a=b;
		}
		sum+=a;
		printf("%d\n", sum);
	}
	return 0;
}