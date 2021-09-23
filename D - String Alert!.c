#include<stdio.h>
int main()
{
	char ch[116];
	int i,j=1,k,m,n,c,s,e;
	scanf("%d %d ", &n, &m);
	while(j<=n)
	{
		scanf("%s", ch);
		for(i=0; ch[i]!='\0'; i++)
		{
			if(ch[i]=='B')
			{
				s=i;
				while(ch[++i]=='B');
				e=i-1;
				c=(e-s+1)/2;
				printf("%d %d", j+c, s+1+c);
				return 0;
			}
		}
		j++;
	}
}