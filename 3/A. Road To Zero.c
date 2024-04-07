#include<stdio.h>
int main()
{
	int t;
	long long total,a, b, x, y, tmp;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if(x>y)
		{
			tmp = x; 
			x = y; 
			y = tmp;
		}


		if(2*a > b)
		{
			total = x*b + (y-x)*a;
		}
		else
			total = (x+y)*a;
		printf("%lld\n", total);

	}
	return 0;
}