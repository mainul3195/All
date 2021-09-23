#include<stdio.h>
int main()
{
	char s[1002];
	scanf("%s", s);
	int i=0,j,k;
	while(s[++i]);
	j=(i-1)/2;
	for(k=0; k<=j; k++)
		if(s[k]!=s[i-k-1])
		{
			printf("NO\n");
			return 0;
		}
	printf("YES");
	return 0;
}