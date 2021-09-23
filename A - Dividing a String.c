#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j,n, count = 1;
	char a[10], b[10], c;
	scanf("%c", &c);
	a[0]=c;
	a[1]=0;
	while(~scanf("%c", &c))
	{
		b[i]=c;
		b[i+1]=0;
		if(strcmp(a,b)!=0)
		{
			puts(a);
			count++;
			strcpy(a,b);
			i=-1;
		}
		i++;
	}
	if(b[strlen(b)-1]!=c)
	{
		puts(b);
		count++;
	}
	printf("%d", count);
	return 0;
}
