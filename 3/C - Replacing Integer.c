#include<stdio.h>

long long min(long long a, long long b)
{
	if(a>b)
		return b;
	else return a;
}

int main()
{
	long long n,k;
	while(~scanf("%lld %lld", &n, &k))
	{
		if(k>n)
			printf("%lld\n", min(n, k-n));
		else printf("%lld\n", min(n%k, k-n%k));
	}
	return 0;
}