#include<stdio.h>
int main()
{
	char s[10002],t[6]="hello";
	int i=0,j=0,f;
	scanf("%s", s);
	while(s[i]!=0)
	{
		if(s[i++]==t[j])
		{
			j++;
			if(j==5)
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}