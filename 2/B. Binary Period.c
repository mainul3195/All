#include<stdio.h>
#include<string.h>
int main()
{
	int t, len, i, n1, n0, max;
	char tt[101];
	scanf("%d", &t);
	while(t--)
	{
		n0=n1=0;
		scanf("%s", tt);
		len = strlen(tt);
		for(i=0; i<len; i++)
		{
			if(tt[i]=='0')
				n0++;
			else
				n1++;
		}
		if(n1==len || n0==len)
			puts(tt);
		else
		{
			max=n0>n1?n0:n1;
			if(tt[0]=='0')
			{
				for(i=0; i<(n0+n1); i++)
					printf("01");
				puts("");
			}
			else
			{
				for(i=0; i<(n0+n1); i++)
					printf("10");
				puts("");
			}
		}
	}
	return 0;
}