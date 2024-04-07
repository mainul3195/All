#include<stdio.h>
int main()
{
	char s[1002], t[1003];
	int i=0,j=0;
	scanf("%s %s", s, t);
	while(s[++i]!=0);
	while(t[++j]!=0);
	printf("%d %d\n%s %s", i,j,s,t);
	return 0;
}