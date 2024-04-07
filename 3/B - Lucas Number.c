#include<stdio.h>

long long lucas(int n)
{
	long long a, b, c;
 	a = 2;
 	b = 1;
 	while(n--)
 	{
 		c = a+b;
 		a=b;
 		b=c;
 	}
	return a;
}
int main()
{
	int a;
	while(~scanf("%d", &a))
	{
		printf("%lld\n",lucas(a));
	}
	return 0;
}