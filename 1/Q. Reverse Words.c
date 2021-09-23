#include<stdio.h>
char s[1000002];
int main()
{
	int i=-2;
	while(~scanf("%s ", s))
	{
		if(i!=-2)
		    printf(" ");
		i=0;
		while(s[++i]);
		while(--i>-1)
			printf("%c", s[i]);
	}
	return 0;
}