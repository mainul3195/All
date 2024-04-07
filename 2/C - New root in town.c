#include<stdio.h>
int main()
{
	long long n,k,x;
	scanf("%lld", &n);
	while(n--)
	{
		scanf("%lld %lld", &k, &x);
		printf("%lld\n", 9*(k-1)+x);
	}
	return 0;
}