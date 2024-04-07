#include<stdio.h>


void test(void)
{
	long long a,n,s;
	scanf("%lld", &a);
	n= ((a+1)/2)-1;
	s = ((n*(n+1)*(2*n+1))/6);
	printf("%lld\n", 8*s);
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}