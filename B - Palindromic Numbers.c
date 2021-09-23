#include<stdio.h>
int main()
{
	int a,b,n,i,r,d;
	while(~scanf("%d %d", &a, &b))
	{
		int count =0;
		for(i=a; i<=b; i++)
		{
			n=i;
			d=0;
			while(n!=0)
			{
				r=n%10;
				d = d*10 + r;
				n/=10;
			}
			if(d==i)
				count++;
		}
		printf("%d\n", count);
	}		
	return 0;
}