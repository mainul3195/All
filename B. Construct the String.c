#include<stdio.h>
int main()
{
	int t, a,b,n,i,j;
	char s[2001], temp[2001], alp[27]="abcdefghijklmnopqrstuvwxyz";
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &a, &b);
		for(i=0, j=0; i<a; i++, j++)
		{
			temp[i]=alp[j];
			if(j==b-1)
				j=-1;
		}
		for(i=0, j=0; i<n; i++, j++)
		{
			s[i]=temp[j];
			if(j==a-1)
				j=-1;
		}
		s[i]='\0';
		puts(s);
	}
	return 0;
}