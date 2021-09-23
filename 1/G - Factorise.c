#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,i,c;
	scanf("%d", &n);
	a=sqrt(n);
	for(i=a; i>=1; i--)
	{
		c=n/i;
		if(i*c==n)
		{
			printf("%d", 2*(i+c));
			return 0;
		}
	}
}