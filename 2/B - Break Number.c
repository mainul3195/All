#include<stdio.h>
#include<math.h>
int main()
{
	int n,c;
	while(~scanf("%d", &n))
	{
		c= log(n)/ log(2);
		n = pow(2,c);
		printf("%d\n", n);
	}
	return 0;
}