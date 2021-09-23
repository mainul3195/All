#include<stdio.h>
int main()
{
	long long n, a, b, s, t;
	while(~scanf("%lld %lld %lld", &n, &a, &b))
	{
		t = n/(a+b);
		s = t*a;
		if(n%(a+b)>a) s += a;
		else s += n%(a+b);
		printf("%lld\n", s);
	}
	return 0;
}