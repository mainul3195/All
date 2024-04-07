#include<stdio.h>
int main()
{
	int t,n,a,b,c,d;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
		if(n*(a-b)<=(c+d)  &&  n*(a+b)>=(c-d))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}