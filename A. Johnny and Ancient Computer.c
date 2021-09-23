#include<stdio.h>
int main()
{
	int t,i;
	long long a,b,c,d;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %lld", &a, &b);
		if(b>a) a^=b^=a^=b;
		if(a%b==0)
		{
			c=a/b;
			for(d=c;d>1;d/=2)
				if(d%2)
					break;
			if(d>1)printf("-1\n");
			else
			{
				for(i=0; c>1; c/=8, i++);
				printf("%d\n", i);
			}
				
		}
		else printf("-1\n");
	}
	return 0;
}