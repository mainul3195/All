#include<stdio.h>
int main()
{
	char s[12], t[12];
	int i=0,j=0;
	scanf("%s %s", s, t);
	while(s[++i]!=0);
	while(t[++j]!=0);
	printf("%d %d\n%s%s\n", i,j,s,t);
	s[0]^=t[0]^=s[0]^=t[0];
	printf("%s %s", s, t);
	return 0;
}