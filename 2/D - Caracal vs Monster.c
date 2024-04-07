#include<stdio.h>
#include<math.h>
int main()
{
	long long i, h, s;
	while(~scanf("%lld", &h))
	{
		i = (log(h)/log(2))+1;
		s = pow(2,i)-1;
		printf("%lld\n", s);
	}
	return 0;
}