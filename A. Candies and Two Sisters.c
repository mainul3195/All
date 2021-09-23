#include<stdio.h>
#include<math.h>
int main()
{
	int t, n,x;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		x=ceil(n/2.0)-1;
		printf("%d\n", x);
	}

	return 0;
}