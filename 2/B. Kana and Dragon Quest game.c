#include<stdio.h>
int main()
{
	int t, a, b,x;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &x, &a, &b);
		while(x>20&&a!=0)
		{
			x=(x/2)+10;
			a--;
		}
		while(b!=0)
		{
			x-=10;
			b--;
		}
		x>0?printf("NO\n"):printf("YES\n");
	}
	return 0;
}