#include<stdio.h>
char c[1000002];
int main()
{
	int i=0,j=0;
	scanf("%s", c);
	while(c[j++]!=0)
		i+=c[j-1]-48;
	printf("%d", i);
	return 0;
}