#include<stdio.h>
int main()
{
	char s[1001];
	int t,n,m,x,y,i,j,k,c,tot;
	scanf("%d", &t);
	while(t--)
	{
		tot =0;
		scanf("%d %d %d %d", &n, &m, &x, &y);
		if(2*x<y)
			y=2*x;
		for(k=0; k<n; k++)
		{
			scanf("%s", s);
			c=0;
			i=-1;
			do
			{
				i++;
				if(s[i]=='.')
					c++;
				else
				{
					tot += y*(c/2)+ x*(c%2);
					c = 0;
				}
			}while(s[i]!='\0');
		}
		printf("%d\n", tot);
	}
	return 0;
}