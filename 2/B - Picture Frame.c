#include<stdio.h>
int main()
{
	int h,w,i,j;
	scanf("%d %d", &h, &w);
	char c;
	for(i=0; i<=h+1; i++)
	{
		for(j=0; j<=w+1; j++)
		{
			if(i==0 || i==h+1 || j==0 || j==w+1)
				printf("#");
			else
			{
				scanf(" %c", &c);
				printf("%c",c);
			}
		}
		puts("");
	}
	return 0;
}