#include<stdio.h>
#include<string.h>
int main()
{
	char s[12];
	int max, i, count, l;
	while(~scanf("%s", s))
	{
		max = 0;
		for(l=strlen(s), i=0; i<l; i++)
		{
			count = 0;
			while((s[i]=='A'|| s[i]=='C' || s[i]=='G' || s[i] == 'T')&& i<l)
			{
				count++;
				i++;
			}
			if(count>max)
				max = count;
		}
		printf("%d\n", max);
	}
	return 0;
}