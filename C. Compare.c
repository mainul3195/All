#include<stdio.h>
int main()
{
	char x[22], y[22];
	scanf("%s %s", x, y);
	int i=0,j;
	while(x[++i]!='\0');
	for(j=0; j<=i; j++)
	{
		if(x[j]<y[j])
		{
			printf("%s", x);
			return 0;
		}
		else if(x[j]>y[j])
		{
			printf("%s", y);
			return 0;
		}
	}
	printf("%s", x);
	return 0;
}