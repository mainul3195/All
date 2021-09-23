#include<stdio.h>
int maxm(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	char s[102], i, n, max, v;
	while(~scanf("%d %s", &n, s))
	{
		v = 0;
		max = 0;
		for(i=0; i<n; i++)
		{
			if(s[i]=='I') v++;
			else v--;
			max = maxm(v, max);
		}
		printf("%d\n", max);
	}
}